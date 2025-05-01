# Makefile

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Library and executable names
LIB = libft.a

# Default target: build the library and link it into the executable
all: $(LIB)

# Build the static library from object files (excluding main.o)
$(LIB): $(filter-out main.o, $(OBJ))
	ar rcs $@ $^

# Compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f *.o

fclean:
	clean $(LIB)