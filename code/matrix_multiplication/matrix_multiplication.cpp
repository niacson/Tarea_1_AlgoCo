#include <chrono>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sys/resource.h>
#include <vector>
#include <string>
#include <sstream>
//Algoritmos
#include "algorithms/naive.h"
#include "algorithms/strassen.h"

std::vector<std::vector<int>> parseInputMatrix(std::string path);
