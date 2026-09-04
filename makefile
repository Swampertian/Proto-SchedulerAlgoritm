# Basic Makefile for template

# Compiler and flags used in every build rule
CC = gcc
CFLAGS  = -Wall -Wextra -Iinclude

# Project directories
SRC_DIR   = src
BUILD_DIR = build
BIN_DIR   = bin

# Add every .c file here
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/core/core.c \
	   $(SRC_DIR)/modules/module.c

# Maps .c files to .o files inside build/, keeping the same structure
# Ex: src/main.c becomes build/src/main.o
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))

# Final program executable
TARGET = $(BIN_DIR)/template

# Sources and binary used by the test target (reuses core/module, swaps main.c for test.c)
TEST_SRCS = tests/test.c \
	    $(SRC_DIR)/core/core.c \
	    $(SRC_DIR)/modules/module.c
TEST_TARGET = $(BIN_DIR)/test

# Default target: builds and runs the program
.PHONY: run clean test

all: $(TARGET)
	@./$(TARGET)

# Linking: combines the .o files and generates the final executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation: turns each .c file into a .o file inside build/
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Creates the output folders if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Same as all, explicit alternate target for a single build
single: $(TARGET)
	@./$(TARGET)

# Builds and runs the tests (bypasses the .o files in build/)
test: | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRCS)
	@./$(TEST_TARGET)

# Cleans up generated files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
