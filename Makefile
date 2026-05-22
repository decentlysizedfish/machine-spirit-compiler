# ==============================================================================
# Makefile for C project using Clang
# Project layout:
#   src/        - C source files (.c)
#   include/    - Header files (.h)
#   build/      - Object files (auto-created)
#   bin/        - Final binary (auto-created)
# ==============================================================================
 
# --- Compiler & Flags ---------------------------------------------------------
 
CC      := clang
CFLAGS  := -Wall -Wextra -Wpedantic -std=c11
IFLAGS  := -Iinclude
LDFLAGS :=                  # Add linker flags here (e.g. -lm for math)
 
# Debug vs Release
# Use: make DEBUG=1   to build with debug symbols and no optimization
#      make           to build with optimization
ifdef DEBUG
    CFLAGS += -g -O0 -DDEBUG
else
    CFLAGS += -O2 -DNDEBUG
endif
 
# --- Directories & Target -----------------------------------------------------
 
SRC_DIR   := src
BUILD_DIR := build
BIN_DIR   := bin
 
TARGET := $(BIN_DIR)/machine_spirit   # <-- Change to your binary name
 
# --- Source & Object Discovery ------------------------------------------------
 
# Find every .c file under src/
SRCS := $(wildcard $(SRC_DIR)/*.c)
 
# Mirror each .c file as a .o inside build/
#   src/main.c  ->  build/main.o
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
 
# --- Default Rule -------------------------------------------------------------
 
.PHONY: all
all: $(TARGET)
 
# --- Link ---------------------------------------------------------------------
 
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "Linked  -> $@"
 
# --- Compile (one rule covers every .c in src/) -------------------------------
 
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "Compiled -> $@"
 
# --- Create output directories if they don't exist ---------------------------
 
$(BUILD_DIR):
	mkdir -p $@
 
$(BIN_DIR):
	mkdir -p $@
 
# --- Convenience targets ------------------------------------------------------
 
.PHONY: run
run: all
	./$(TARGET)
 
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Cleaned build artifacts."
 
.PHONY: rebuild
rebuild: clean all
 
# Print discovered sources & objects (useful for debugging the Makefile itself)
.PHONY: info
info:
	@echo "Sources : $(SRCS)"
	@echo "Objects : $(OBJS)"
	@echo "Target  : $(TARGET)"
 