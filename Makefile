CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS :=

SRC_DIR := src
BUILD_DIR := build
TARGET := eventflow

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

.PHONY: all clean run docs valgrind

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

# Requires doxygen to be installed locally;
docs:
	doxygen Doxyfile

# Requires valgrind to be installed locally;
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
