/*
    Entiendo que en este archivo hay que agregar los algoritmos que tenemos, manejar la lectura de los archivos de texto y generar las salidas
*/

#include <chrono>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
//Algoritmos
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

std::vector<std::string> getInputFileNames(std::string path) {
    std::vector<std::string> output;
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        output.push_back(entry.path().string());
    }
    return output;
}

int main () {
    std::map<int, std::vector<double>> info;
    std::vector<std::string> fileNames = getInputFileNames("data/easy");
    std::vector<int> nums;
    for (auto const &fileName : fileNames) {
        nums = parseInputVect(fileName);
        int key = nums.size();
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(nums, 0, nums.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> QSduration = end - start;
        nums.clear();
        //#############################################################################
        nums = parseInputVect(fileName);
        start = std::chrono::high_resolution_clock::now();
        mergeSort(nums, 0, nums.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> MSduration = end - start;
        nums.clear();
        //#############################################################################
        nums = parseInputVect(fileName);
        start = std::chrono::high_resolution_clock::now();
        sortArray(nums);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> Sduration = end - start;
        nums.clear();
        //############################################################################
        if (info.count(key) == 0) {
            info.insert({key, {}});
        }
        info.at(key).push_back(QSduration.count());
        info.at(key).push_back(MSduration.count());
        info.at(key).push_back(Sduration.count());
        std::cout << "sorted: " << fileName << std::endl;
    }
    std::ofstream output("data/measurements/a.txt");
    int entryCount = 0;
    for (auto const &pair : info) {
        output << pair.first << ": ";
        for (auto const &data : pair.second) {
            output << data << " ";
            entryCount++;
            if (entryCount == 3) {
                output << " | ";
                entryCount = 0;
            }
        }
        output << "\n";
    }
    output << "\n";
    return 0;
}

