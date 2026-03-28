CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -o2

SRCSORT = sorting1.cpp $(wildcard algorithms/*.cpp)
OBJSORT = $(SRCSORT:.cpp=.o)

TARGET = sort

all: $(TARGET)

$(TARGET): $(OBJSORT)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJSORT)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJSORT) $(TARGET)

hola:
	echo "hola"
