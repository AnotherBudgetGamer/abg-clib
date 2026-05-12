CC = gcc
AR = ar

CFLAGS = -Wall -Wextra -g -pedantic -std=c99 -Iinclude

BUILD_DIR = build
TARGET = $(BUILD_DIR)/libabg_core.a

PREFIX ?= /usr/local

SRCS = \
	src/abg_core.c \
	src/abg_math.c \
	src/abg_random.c

OBJS = $(SRCS:src/%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(AR) rcs $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: src/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	cp include/abg_core.h $(PREFIX)/include/
	cp include/abg_math.h $(PREFIX)/include/
	cp include/abg_random.h $(PREFIX)/include/
	cp $(TARGET) $(PREFIX)/lib/

uninstall:
	rm -f $(PREFIX)/include/abg_core.h
	rm -f $(PREFIX)/include/abg_math.h
	rm -f $(PREFIX)/include/abg_random.h
	rm -f $(PREFIX)/lib/libabg_core.a

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all