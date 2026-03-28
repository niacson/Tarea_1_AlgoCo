TARGET = sorting
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -o2

SRC = sorting.cpp $(wildcard algorithms/*.cpp)
OBJ_DIR = obj
OBJS = $(OBJ_DIR)/sorting.o  \
	   $(OBJ_DIR)/mergesort.o \
	   $(OBJ_DIR)/quicksort.o \
	   $(OBJ_DIR)/sort.o

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: algorithms/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@rm -r $(OBJ_DIR)
	@rm -f $(TARGET)

run:
	@rm -f data/measurements/m.txt data/measurements/q.txt data/measurements/s.txt
	@echo "Iniciando pruebas de ordenamiento"
	@chmod +x runner.sh
	@./runner.sh
	@echo "Pruebas finalizadas"
