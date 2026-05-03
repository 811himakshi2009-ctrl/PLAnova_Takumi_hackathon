#!/usr/bin/env python3
"""Copy Canva (or any) splash from ../logo into Graphics.ocg startup assets.

Looks for the first image file in the repository `logo/` folder (non-recursive),
updates `planet/Graphics.ocg/StartupMainMenuBG.png` (loader + menu backdrop) and
`planet/Graphics.ocg/StartupLogo.png` to match so no legacy logo remains.

Requires Pillow: pip install pillow
"""
from __future__ import annotations

import sys
from pathlib import Path

try:
    from PIL import Image
except ImportError:
    print("Install Pillow: pip install pillow", file=sys.stderr)
    sys.exit(1)

ROOT = Path(__file__).resolve().parents[1]
LOGO_DIR = ROOT / "logo"
GFX = ROOT / "planet" / "Graphics.ocg"
EXTS = {".png", ".jpg", ".jpeg", ".bmp", ".webp"}


def main() -> int:
    src: Path | None = None
    if len(sys.argv) >= 2:
        cand = Path(sys.argv[1]).expanduser().resolve()
        if cand.is_file() and cand.suffix.lower() in EXTS:
            src = cand
        else:
            print(f"Not a supported image file: {cand}", file=sys.stderr)
            return 1
    elif LOGO_DIR.is_dir():
        for p in sorted(LOGO_DIR.iterdir()):
            if p.is_file() and p.suffix.lower() in EXTS:
                src = p
                break

    GFX.mkdir(parents=True, exist_ok=True)

    if src:
        im = Image.open(src).convert("RGBA")
        im.save(GFX / "StartupMainMenuBG.png", "PNG")
        im.save(GFX / "StartupLogo.png", "PNG")
        print(f"Updated StartupMainMenuBG.png and StartupLogo.png from {src}")
        return 0

    LOGO_DIR.mkdir(parents=True, exist_ok=True)
    print(
        f"No image: add one under {LOGO_DIR} or pass a path, e.g.\n"
        f"  python tools/update_startup_branding.py \"C:\\path\\to\\splash.png\"\n"
        f"Supported extensions: {', '.join(sorted(EXTS))}",
        file=sys.stderr,
    )
    return 1


if __name__ == "__main__":
    sys.exit(main())
