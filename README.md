# ABG C Library
---
ABG C Library is a small personal C utility library used for learning, practice, and reusable helper functions across C projects.

The current version focuses on basic math helpers such as clamping, interpolation, remapping values, min/max helpers, float comparison, and safe division.

This project is intentionally simple and is meant to be easy to build, inspect, and expand.

---

## Project Structure
```txt
abg-clib/
├── Makefile
├── build.sh
├── build.bat
├── include/
│   ├── abg_core.h
│   └── abg_math.h
├── src/
│   └── abg_math.c
└── build/
    ├── linux/
    └── win/
```

### Important Folders
| Folder    | Purpose        |
| :-----    | ------:        |
| include/  | Public Headers |
| src/	    | C source files |
| build/    | Build Output   |

The `build/` folder is generated during compilation if not present.

### Headers

The main umbrella header is:
```C
#include "abg_core.h"
```
This header includes all the available ABG library modules.

Individual headers can also be included directly:
```C
#include "abg_math.h"
```

## Build Output
This project builds into a static single file header library:
```
libabg.a
```
Different build folders are used for Linux and Windows and do not overwrite each other.

## Build Requirements
You will need a C compiler and basic build tools

### For Linux/WSL
Install build tools:
```Bash
sudo apt update
sudo apt install build-essential
```

This will give access to the following for this library:
```
gcc
make
ar
```
[gcc](https://gcc.gnu.org/) is the GNU compiler.

[make](https://www.gnu.org/software/make/) controls the generation of executables and other non-source files.

[ar](https://www.man7.org/linux/man-pages/man1/ar.1.html) creates, modifies, and extracts from archives and is used to bundle our library.

### For Windows PowerShell / Command Prompt
For `build.bat` make sure `gcc` and `ar` are available in your PATH. [Here](https://gcc.gnu.org/install/configure.html) is some more information.

If using MSYS2 UCRT64 tools from PowerShell, confirm they are available:
```PowerShell
gcc --version
ar --version
```
If gcc is not present, download MSYS2 and update the packages:
```Powershell
pacman -Syu
pacman -Su
```
Install gcc:
```PowerShell
pacman -S mingw-w64-x86_64-gcc
```
Add C:\msys64\wingw64\bin to your system PATH.

### Building With Make
The Makefile supports a custom `BUILD_DIR` variable so each environment can output to its own folder.

#### Linux / WSL
From project root:
```Bash
make all BUILD_DIR=build/linux
```
Output:
```
build/linux/libabg.a
```

#### MSYS2 UCRT64
From project root:
```Bash
mingw32-make all BUILD_DIR=build/ucrt
```
Output:
```
build/ucrt/libabg.a
```

#### Building with build.sh
The `build.sh` script is intended for Linux, WSL, Git Bash, or MSYS2-style Bash terminals. This is the recommended build option.

Before running for the first time, make it executable:
```Bash
chmod +x build.sh
```
Then run:
```Bash
./build.sh
```
Output:
```
build/linux/libabg.a
```

### Building with build.bat
The `build.bat` script is intended for Windows Command Prompt of PowerShell.

#### PowerShell
From the project root:
```PowerShell
.\build.bat
```

#### Command Prompt
```bat
build.bat
```
Output:
```
build/win/libabg.a
```

### Cleaning Build Files
To remove generated build files using Make:
```Bash
make clean
```
This removes the `build/` directory.
You can also manually delete the `build/` folder.


## Example Usage in Another C Project
After building the library, another C project can include the headers and link against the static library.

Example:
```C
#include "abg_core.h"

int main(void) {
    float value = ABG_ClampFloat(15.0f, 0.0f, 10.0f);
    return 0;
}
```
Example compile command:
```Bash
gcc main.c -Ipath/to/agb-clib/include path/to/agb-clib/build/linux/libabg.a -o main
```
Adjust the library path depending on your environment:
```
build/linux/libabg.a
build/win/libabg.a
```

## Notes
This library is currently a v.0.1 learning project and will continue to be developed. 

The build setup intentionally includes different build methods for learning purposes:
```
Makefile
build.sh
build.bat
```
This allows testing different build workflows across Linux, WSL, MSYS2/UCRT64, and Windows.