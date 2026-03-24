/*Fuente: https://www.geeksforgeeks.org/cpp/cpp-program-for-quicksort/*/
#include "quicksort.h"

int partition(std::vector<int> &vec, int low, int high) {

    // Selecting last element as the pivot
    int pivot = vec[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    std::swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(std::vector<int> &vec, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec, low, high);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}
