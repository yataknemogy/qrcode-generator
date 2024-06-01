# QR Code Generator

This project is a simple QR code generator written in C++ using the `libqrencode` library. It encodes a given string into a QR code and saves it as a PBM (Portable Bitmap) image file.

## Features

- Generates QR codes from a given string.
- Saves the QR code as a PBM image file.

## Requirements

- C++ compiler
- `libqrencode` library
- `vcpkg` (recommended for managing dependencies)

## Installation

### Windows

1. **Install `vcpkg`**:
   ```sh
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
2. **Install libqrencode using `vcpkg`**:
     ```sh
     .\vcpkg install qrencode
3. **Integrate vcpkg with Visual Studio**:
     ```sh
     .\vcpkg integrate install

### macOS

1. **Install HomeBrew (if not already installed)**:
   ```sh
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
2. **Install `libqrencode` using Homebrew**:
   ```sh
   brew install qrencode

### Linux (Ubuntu)

1. Install `libqrencode` using APT:
   ```sh
   sudo apt-get update
   sudo apt-get install libqrencode-dev


## Setup in Visual Studio

1. **Open your project in Visual Studio.**

2. Add incluse directories**:
   - Open Project > Properties.
   - Go to VC++ Directories > Include Directories.
   - Add the path to vcpkg include directory:
     ```vbnet
      C:\path\to\vcpkg\installed\x64-windows\include

3. **Add library directories**:
  - Go to `VC++ Directories > Library Directories`.
  - Add the path to `vcpkg` library directory:
    ```vbnet
    C:\path\to\vcpkg\installed\x64-windows\lib

4. Add additional dependencies:
   - Go to `Linker > Input > Additional Dependencies`
   - Add `qrencode.lib` 
