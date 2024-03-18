# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11 -g

# Source directory
SRC_DIR = src

# Object directory
OBJ_DIR = bin

# Include directory
INC_DIR = include

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Executable names
TARGETS = $(patsubst $(SRC_DIR)/%.c, %, $(SRCS))

# Default rule to build all executables
all: $(TARGETS)

# Rule to build each executable
$(TARGETS): % : $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) $< -o $(OBJ_DIR)/$@ -I$(INC_DIR)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

# Create bin directory if it doesn't exist
$(shell mkdir -p $(OBJ_DIR))

# Clean rule to remove object files and executables
clean:
	rm -rf $(OBJ_DIR) $(TARGETS:%=$(OBJ_DIR)/%)