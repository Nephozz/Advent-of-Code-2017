# Compiler
CC = gcc

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = $(SRCS:.c=)

# Compile
all: $(TARGET)

# Rules
$(TARGET): $(OBJS)
	$(CC) -o $@ $@.o

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

