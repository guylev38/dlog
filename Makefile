# 1. Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# 2. Targets
TARGET = dlog_test
LIB_OBJ = dlog.o
TEST_OBJ = main.o

# 3. Default Rule (The one that runs when you just type 'make')
all: $(TARGET)

# 4. Linking the final executable
$(TARGET): $(LIB_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(LIB_OBJ) $(TEST_OBJ)

# 5. Compiling the Logger Module
# This creates logger.o from logger.c
dlog.o: dlog.c dlog.h
	$(CC) $(CFLAGS) -c dlog.c

# 6. Compiling the Test Main
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# 7. Cleanup Rule
clean:
	rm -f *.o $(TARGET)

# 8. Phony Targets (Prevents conflict with files named 'clean' or 'all')
.PHONY: all clean