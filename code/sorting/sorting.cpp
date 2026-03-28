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
#include <sys/resource.h>
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

long getMemUsage() {
    rusage usage_data;
    getrusage(RUSAGE_SELF, &usage_data);
    //Tranformacion de Kib a bytes
    return long(usage_data.ru_maxrss);
}

int main () {
    std::map<int, std::vector<double>> timeMeasurements;
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
        long peakMemUsage = getMemUsage();
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
        if (timeMeasurements.count(key) == 0) {
            timeMeasurements.insert({key, {}});
        }
        timeMeasurements.at(key).push_back(QSduration.count());
        timeMeasurements.at(key).push_back(MSduration.count());
        timeMeasurements.at(key).push_back(Sduration.count());
        std::cout << "sorted: " << fileName;
        std::cout << " Ram Usage: " << peakMemUsage << std::endl;
    }
    std::ofstream output("data/measurements/a.txt");
    int entryCount = 0;
    for (auto const &pair : timeMeasurements) {
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
    output.close();
    return 0;
}

