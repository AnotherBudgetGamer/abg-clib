CC = gcc
AR = ar

CFLAGS = -Wall -Wextra -g -pedantic -std=c99 -Iinclude
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lXrandr -lXinerama -lXi -lXcursor

BUILD_DIR = build
TARGET = $(BUILD_DIR)/libabg.a

SRCS = src/abg_math.c
OBJS = $(SRCS:src/%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rcs $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: src/%.c include/abg_math.h
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LIBS) -c $< -o $@

clean:
	rm -rf build