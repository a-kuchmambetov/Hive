# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g  # Common flags with debugging info

# Executable name
TARGET = rush-02

# List of source files
SRC = main.c \
      print.c \
      dict_get.c \
      str_lib.c \
      ft_parse_dict.c \
      ft_parse_dict_helper.c \
      ft_process_entry.c \
      convert_num.c \
      write_error.c

# List of object files (corresponding to the source files)
OBJ = $(SRC:.c=.o)

# Default rule to build the program
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile each .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build
clean:
	rm -f $(OBJ)

# Remove object files and the executable
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

# Phony targets (these are not actual files)
.PHONY: all clean fclean re run
