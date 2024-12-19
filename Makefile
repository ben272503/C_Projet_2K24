# Name of the compiler
CC = gcc

# General compilation options
CFLAGS = -Wall -Wextra -I.

# List of object files
OBJS = led.o sleep.o

# Name of the executable
TARGET = app_test_fakeled

# Default rule: compile the executable
all: $(TARGET)

# Generate the executable
$(TARGET): app_test_fakeled.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ app_test_fakeled.c $(OBJS) -lpthread

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean generated files
clean:
	rm -f $(OBJS) $(TARGET)
