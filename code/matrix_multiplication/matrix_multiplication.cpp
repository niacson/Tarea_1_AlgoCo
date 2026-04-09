// Autor: Ignacio Cofré Sandoval 202304140-8
// Ramo: INF221
// Semestre: 2026-1

#include <chrono>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sys/resource.h>
#include <vector>
#include <string>
#include <sstream>
#include <optional>
//Algoritmos
#include "algorithms/naive.h"
#include "algorithms/strassen.h"

namespace fs = std::filesystem;

std::optional<std::vector<std::vector<int>>> parseInputMatrix(std::string &path);

void writeResMatrix(std::string path, std::vector<std::vector<int>> &res);

void writeMeasurementRes(std::string path, int size, long duration, long peakMemUsage);

std::string buildDestinationPath(std::string &originalPath);

long getMemUsage();

enum ALGORITHMS : char {
    STRASSEN = 's',
    NAIVE = 'n'
};

int main (int argc, char *argv[]) {
    if (argc < 4) {
        std::cerr << "Metodo de uso: ./matmul <algritmo (s: strassen / n: naive)> <input_path_matrix_A> <input_path_matrix_B>" << std::endl;
        return 1;
    }
    ALGORITHMS algo = static_cast<ALGORITHMS>(*argv[1]);
    std::string inputPathA = argv[2];
    std::string inputPathB = argv[3];
    auto testA = parseInputMatrix(inputPathA);
    if(!testA) {
        std::cerr << "No se pudo abrir el archivo " << inputPathA << std::endl;
        return 2;
    }
    auto testB = parseInputMatrix(inputPathB);
    if (!testB) {
        std::cerr << "No se pudo abrir el archivo " << inputPathB << std::endl;
        return 2;
    }
    std::vector<std::vector<int>> matrixA = *testA;
    std::vector<std::vector<int>> matrixB = *testB;
    int size = matrixA.at(0).size();
    std::vector<std::vector<int>> res;
    auto start = std::chrono::high_resolution_clock::now();
    switch (algo) {
        case STRASSEN:
            res = strassen(matrixA, matrixB);
            break;
        case NAIVE:
            res = naiveMatMul(matrixA, matrixB);
            break;
    }
    long peakMemUsage = getMemUsage();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    writeResMatrix(buildDestinationPath(inputPathA), res);
    std::stringstream measurePath;
    measurePath << "data/measurements/" << algo << ".txt";
    writeMeasurementRes(measurePath.str(), size, duration, peakMemUsage);
    return 0;
}

std::optional<std::vector<std::vector<int>>> parseInputMatrix(std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return std::nullopt;
    }
    std::vector<std::vector<int>> output;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<int> row;
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
        output.push_back(row);
    }
    return output;
}

long getMemUsage() {
    rusage usage_data;
    getrusage(RUSAGE_SELF, &usage_data);
    return long(usage_data.ru_maxrss);
}

std::string buildDestinationPath(std::string &originalPath) {
    std::stringstream path;
    std::string aux = originalPath.substr(18);
    std::string name = aux.substr(0, aux.size() - 5);
    path << "data/matrix_output/" << name << "out.txt";
    return path.str();
}

void writeResMatrix(std::string path, std::vector<std::vector<int>> &res) {
    std::ofstream file(path);
    for (const auto &row : res) {
        for (const int &num : row) {
            file << num << " ";
        }
        file << "\n";
    }
    file.close();
}

void writeMeasurementRes(std::string path, int size, long duration, long peakMemUsage) {
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









