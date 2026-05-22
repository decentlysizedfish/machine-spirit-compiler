# Compiler + flags
CC := clang
CFLAGS := -Wall -Wextra -Werror -Iinclude
DEPS = .include
OBJ := .src
TARGET := bin/mspirit


compmake: $(OBJ)/main.o $(OBJ)/lexer.o $(OBJ)/parser.o
	$(CC) -o $(TARGET) $^ $(CFLAGS)
	// ahh