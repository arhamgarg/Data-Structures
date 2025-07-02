CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

SRC = src/main.cpp src/List.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = list

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
