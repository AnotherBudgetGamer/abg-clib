CC = gcc
AR = ar

CFLAGS = -Wall -Wextra -g -pedantic -std=c99 -Iinclude

BUILD_DIR = build
TARGET = $(BUILD_DIR)/libabg_core.a
PREFIX = /usr/local

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
	sudo cp include/abg_core.h $(PREFIX)/include/
	sudo cp include/abg_math.h $(PREFIX)/include/
	sudo cp include/abg_random.h $(PREFIX)/include/
	sudo cp $(TARGET) $(PREFIX)/lib/

uninstall:
	sudo rm -f $(PREFIX)/include/abg_core.h
	sudo rm -f $(PREFIX)/include/abg_math.h
	sudo rm -f $(PREFIX)/include/abg_random.h
	sudo rm -f $(PREFIX)/lib/libabg_core.a

clean:
	rm -rf $(BUILD_DIR)

rebuild: clean all