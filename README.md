# ABG C Library
---
ABG C Library is a small personal C utility library used for learning, practice, and reusable helper functions across C projects.

The current version focuses on basic math helpers such as clamping, interpolation, remapping values, min/max helpers, float comparison, and safe division.

This project is intentionally simple and is meant to be easy to build, inspect, and expand.

---

## Table of Contents
- [Project Structure](#project-structure)
- [Important Folders](#important-folders)
- [Headers](#headers)
- [Build Output](#build-output)
- [Build Requirements](#build-requirements)
- [Build for Linux](#for-linuxwsl)
- [Build for Windows](#for-windows-powershell--command-prompt)
- [Build with Make](#building-with-make)
- [Build with build.sh](#building-with-buildsh)
- [Build with build.bat](#building-with-buildbat)
- [Cleaning Build Files](#cleaning-build-files)
- [Example Usage](#example-usage-in-another-c-project)
- [Notes](#notes)

## Project Structure
```txt
abg-clib/
├── Makefile
├── include/
│   ├── abg_core.h
│   ├── abg_math.h
│   └── abg_random.h
├── src/
│   ├── abg_core.c
│   ├── abg_math.c
│   └── abg_random.c
├── examples/
│   └── core_test.c
└── build/
    ├── abg_core.o
    ├── abg_math.o
    ├── abg_random.o
    └── libabg_core.a
```

### Important Folders
| Folder    | Purpose        |
| :-----    | :------        |
| include/  | Public Headers |
| src/	    | C source files |
| examples/ | Test Programs  |
| build/    | Build Output   |

The `build/` folder is generated during compilation if not present.

### Headers

The core library is a portable collection of modules, currently including:
```txt
abg_core
├── abg_math
└── abg_random
```
The goal is for `abg-core` to contain general purpose C helpers useful in most projects.

Either `abg_math` or `abg_random` can be included as individual headers directly:
```C
#include "abg_math.h"
#include "abg_random.h"
```

## Build Output
This project builds into a static library archive:
```
libabg.a
```
Default output:
```
build/libabg_core.a
```
The static library contains the compiled files for the core modules:
```
build/abg_core.o
build/abg_math.o
build/abg_random.o
```

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
- [gcc](https://gcc.gnu.org/) is the GNU compiler.

- [make](https://www.gnu.org/software/make/) controls the generation of executables and other non-source files.

- [ar](https://www.man7.org/linux/man-pages/man1/ar.1.html) creates, modifies, and extracts from archives and is used to bundle our library.
---
### Building with Make
From project root:
```Bash
make
```
This builds:
```
build/libabg_core.a
```
To rebuild from scratch:
```Bash
make rebuild
```
To clean generated files:
```Bash
make clean
```
---
### Installing on Linux / WSL
After building the library, it can be installed into the WSL/Linux system paths.

From project root:
```Bash
sudo make install
```
This copies the public headers to:
```
/usr/local/include/
```
And the static library to:
```
/usr/local/lib/
```

Installed files:
```
/usr/local/include/abg_core.h
/usr/local/include/abg_math.h
/usr/local/include/abg_random.h
/usr/local/lib/libabg_core.a
```
---
### Testing Install
To verify installation, check if files exist:
```Bash
ls -l /usr/local/include/abg_core.h
ls -l /usr/local/include/abg_math.h
ls -l /usr/local/include/abg_random.h
ls -l /usr/local/lib/libabg_core.a
```
Create a temporary directory:
```Bash
mkdir -p /tmp/abg-install-test
cd /tmp/abg-install-test
```
Create a file:
```Bash
nano test.c
```
Add:
```C
#include <stdio.h>
#include "abg_core.h"

int main(void) {
    ABG_Core_Init();

    printf("Roll: %d\n", ABG_RandInt(1, 6));
    printf("Clamp: %.2f\n", ABG_ClampFloat(125.0f, 0.0f, 100.0f));

    return 0;
}
```
Compile with local include or library paths:
```Bash
gcc test.c -labg_core -o test
```
---
### Using ABG Core in Other Projects
After installing, another C project on the user/device can use:
```C
#include "abg_core.h"
```

Example:
```C
#include <stdio.h>
#include "abg_core.h"

int main(void) {
    ABG_Core_Init();

    int roll = ABG_RandInt(1, 6);
    float health = ABG_ClampFloat(125.0f, 0.0f, 100.0f);

    printf("Roll: %d\n", roll);
    printf("Health: %.2f\n", health);

    return 0;
}
```
Compile:
```Bash
gcc main.c -labg_core -o main
```
---
### Cleaning Build Files
To remove generated build files:
```Bash
make clean
```
This removes:
```
/build
```
---
## Future Modules
The current focus is on the core library and its uses. Other modules are being planned and developed.

There is a ABG_UI module in the works that uses Raylib as a renderer. 


## Notes
This library is currently a v.0.1 learning project and will continue to be developed. The main goal of this project is to be a small, reusable C utility library across personal projects.

