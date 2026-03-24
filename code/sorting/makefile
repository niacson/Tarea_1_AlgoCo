CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRC = sorting.cpp $(wildcard algorithms/*.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = prog

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
