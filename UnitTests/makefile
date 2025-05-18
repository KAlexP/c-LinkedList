# This is the makefile for the unit_tests

CC = gcc
CFLAGS = -Wall -I/opt/homebrew/include 
LDFLAGS = -L/opt/homebrew/lib -lcunit
TARGET = unit_test
SRC = unit_test.c

# Selects the interface: basic, console, or automated
INTERFACE ?= basic 
UPPER_INTERFACE := $(shell echo $(INTERFACE) | tr a-z A-Z)

# Default target
all: $(TARGET)

# asks to compile the program
$(TARGET): $(SRC) 
	$(CC) $(CFLAGS) -DINTERFACE_$(UPPER_INTERFACE) $(SRC) -o $(TARGET) $(LDFLAGS)

# Runs the executable
run: $(TARGET)
	./$(TARGET)

# compile rules for a debug version of the executable with memory analysis on
debug: CFLAGS += -g -O0 -DDEBUG -fsanitize=address -fno-omit-fram-pointer 
debug: LDFLAGS += -fsanitize=address
debug: $(TARGET) 
	ASAN_OPTIONS=detect=1 ./$(TARGET)

# compile rules for a non debug version of the executable
release: CFLAGS += -O2
release: clean $(TARGET) 

# cleans up the directory of unnecessary files
clean: 
	rm -f $(TARGET) CUnitAutomated-*.xml

# PHONY makes the 'phony' list execute without regard to file status of the list
.PHONY: all run clean debug
