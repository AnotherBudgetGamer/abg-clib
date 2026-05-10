@echo off

if not exist build mkdir build
if not exist build\win mkdir build\win

gcc -Wall -Wextra -g -pedantic -std=c99 ^
    -Iinclude ^
    -c src\abg_math.c ^
    -o build\win\abg_math.o

ar rcs build\win\libabg.a build\win\abg_math.o

echo Built build\win\libabg.a