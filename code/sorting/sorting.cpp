#include <chrono>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sys/resource.h>
#include <vector>
#include <string>
#include <sstream>
//Implementacion de los algoritmos de ordenamiento (y luego los de multiplicacion de matrices)
#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include "algorithms/sort.h"

namespace fs = std::filesystem;

//Funciones auxiliares
std::vector<int> parseInputVect(std::string path);

long getMemUsage();

void writeDataFile(std::string path, int size, long peakMemUsage, long duration);

enum ALGORITHMS : char {
    MERGE = 'm',
    QUICK = 'q',
    SORT = 's'
};

int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Modo de uso: ./sorting <algoritmo(q (quickSort), m (mergeSort), s (std::sort))> <input>" << std::endl;
        return 1;
    }
    ALGORITHMS algo = static_cast<ALGORITHMS>(*argv[1]);
    std::string inputPath = argv[2];
    std::vector<int> input = parseInputVect(inputPath);
    auto start = std::chrono::high_resolution_clock::now();
    switch (algo) {
        case MERGE:
            mergeSort(input, 0, input.size() - 1);
            break;
        case QUICK:
            quickSort(input, 0, input.size() - 1);
            break;
        case SORT:
            sortArray(input);
            break;
    }
    long peakMemUsage = getMemUsage();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    // Formato escritura en archivo .txt:
    // Nombre archivo: algoritmo.txt
    // tamaño entrada, tiempo, memoria |
    std::stringstream path;
    path << "data/measurements/" << algo << ".txt";
    std::cout << "Sorted: " << inputPath << std::endl;
    writeDataFile(path.str(), input.size(), peakMemUsage, duration);
    return 0;
}

long getMemUsage() {
    rusage usage_data;
    getrusage(RUSAGE_SELF, &usage_data);
    return long(usage_data.ru_maxrss);
}

std::vector<int> parseInputVect(std::string path) {
    std::ifstream file(path);
    std::vector<int> output;
    int num;
    while (file >> num) {
        output.push_back(num);
    }
    return output;
}

void writeDataFile(std::string path, int size, long peakMemUsage, long duration) {
    if (fs::exists(path)) {
        //Escribo sobre el archivo ya creado
        std::ofstream file(path, std::ios::app);
        file << size << "," << duration << "," << peakMemUsage << "|";
    }
    else {
        //Creo el archivo y escribo en el
        std::ofstream file(path);
        file << size << "," << duration << "," << peakMemUsage << "|";
    }
}
