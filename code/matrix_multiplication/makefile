TARGET = matmul
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -o2

SRC = matrix_multiplication.cpp $(wildcard algorithms/*.cpp)
OBJ_DIR = obj
OBJS = $(OBJ_DIR)/matrix_multiplication.o  \
	   $(OBJ_DIR)/naive.o \
	   $(OBJ_DIR)/strassen.o

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
	@rm -f data/measurements/s.txt data/measurements/n.txt
	@echo "Iniciando multiplicacion de matrices"
	@chmod +x runner.sh
	@./runner.sh
	@echo "Multiplicaciones finalizadas"
