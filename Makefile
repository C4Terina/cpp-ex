# Makefile

CXX = g++
CXXFLAGS = -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic-errors -ggdb

TARGET = program

SRCS := main.cpp student.cpp subject.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile C++ source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)