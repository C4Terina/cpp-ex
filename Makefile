# Makefile

CXX = g++
CXXFLAGS = -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic-errors -ggdb

TARGET = program

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
