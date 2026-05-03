# Builds PLAnova-important-code-only.zip for hosts with a ~1000 file limit (e.g. itch.io).
# Includes only source + build metadata needed to compile; excludes planet, builds, docs, .git.
$ErrorActionPreference = 'Stop'
$MaxFiles = 950

$Root = Split-Path $PSScriptRoot -Parent
if (-not (Test-Path (Join-Path $Root 'CMakeLists.txt'))) {
    Write-Error "Could not find project root (CMakeLists.txt) above tools/."
    exit 1
}

$Stage = Join-Path $env:TEMP ("PLAnova-code-only-" + [Guid]::NewGuid().ToString('n'))
New-Item -ItemType Directory -Force -Path $Stage | Out-Null

$Dirs = @('src', 'include', 'cmake', 'tools', 'vendor', 'masterserver', 'tests')
foreach ($d in $Dirs) {
    $srcPath = Join-Path $Root $d
    if (Test-Path $srcPath) {
        Copy-Item $srcPath (Join-Path $Stage $d) -Recurse -Force
    }
}

if (Test-Path (Join-Path $Root 'logo')) {
    Copy-Item (Join-Path $Root 'logo') (Join-Path $Stage 'logo') -Recurse -Force
}

$RootFiles = @(
    'CMakeLists.txt',
    'Version.txt',
    'planova.appdata.xml',
    '.gitignore',
    'LICENSE',
    'LICENSE.md',
    'CONTRIBUTING.md'
)
foreach ($f in $RootFiles) {
    $p = Join-Path $Root $f
    if (Test-Path $p) { Copy-Item $p $Stage -Force }
}

$FileCount = (Get-ChildItem -Path $Stage -Recurse -File).Count
Write-Host "Staged file count: $FileCount (limit $MaxFiles)"
if ($FileCount -gt $MaxFiles) {
    Remove-Item $Stage -Recurse -Force -ErrorAction SilentlyContinue
    Write-Error "Too many files ($FileCount). Remove optional folders from this script or exclude more paths."
    exit 1
}

$ZipPath = Join-Path $Root 'PLAnova-important-code-only.zip'
if (Test-Path $ZipPath) { Remove-Item $ZipPath -Force }

$items = @(Get-ChildItem -LiteralPath $Stage)
Compress-Archive -Path ($items | ForEach-Object { $_.FullName }) -DestinationPath $ZipPath -CompressionLevel Optimal -Force

Remove-Item $Stage -Recurse -Force

Add-Type -AssemblyName System.IO.Compression.FileSystem
$zip = [System.IO.Compression.ZipFile]::OpenRead($ZipPath)
$zipEntries = $zip.Entries.Count
$zip.Dispose()
Write-Host "Created: $ZipPath"
Write-Host "ZIP entry count: $zipEntries"
if ($zipEntries -gt 1000) {
    Write-Warning "ZIP still has over 1000 entries; platform may reject."
}
