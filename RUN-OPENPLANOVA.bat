@echo off
REM Game must start with project root as working directory (planet/, etc.)
cd /d "%~dp0"
start "" "%~dp0build-vcpkg\openplanova.exe"
