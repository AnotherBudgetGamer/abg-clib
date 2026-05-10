#!/bin/bash

mkdir -p build/linux

gcc -Wall -Wextra -g -pedantic -std=c99 \
    -Iinclude \
    -c src/abg_math.c \
    -o build/linux/abg_math.o

ar rcs build/linux/libabg.a build/linux/abg_math.o

echo "Built build/linux/libabg.a"