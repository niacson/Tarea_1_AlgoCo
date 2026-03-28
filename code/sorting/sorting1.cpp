#include <chrono>
#include <fstream>
#include <iostream>
#include <sys/resource.h>
#include <vector>
#include <string>
//Implementacion de los algoritmos de ordenamiento (y luego los de multiplicacion de matrices)
#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include "algorithms/sort.h"

std::vector<int> parseInputVect(std::string path) {
    std::ifstream file(path);
    std::vector<int> output;
    int num;
    while (file >> num) {
        output.push_back(num);
    }
    return output;
}

long getMemUsage() {
    rusage usage_data;
    getrusage(RUSAGE_SELF, &usage_data);
    return long(usage_data.ru_maxrss);
}

enum ALGORITHMS : char {
    MERGE = 'm',
    QUICK = 'q',
    SORT = 's'
};

int main (int argc, char *argv[]) {
    ALGORITHMS algo = static_cast<ALGORITHMS>(*argv[1]);
    std::string inputPath = argv[2];
    std::vector<int> test = parseInputVect(inputPath);
    auto start = std::chrono::high_resolution_clock::now();
    long preMemUsage = getMemUsage();
    switch (algo) {
        case MERGE:
            mergeSort(test, 0, test.size() - 1);
            break;
        case QUICK:
            quickSort(test, 0, test.size() - 1);
            break;
        case SORT:
            sortArray(test);
            break;
    }
    long postMemUsage = getMemUsage();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    for (int num : test) {
        std::cout << num << " ";
    }
    std::cout << "\n" << "tiempo: " << duration << std::endl;
    std::cout << "memoria: " << postMemUsage << std::endl;
    return 0;
}
