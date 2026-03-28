/*
    Fuente: Implementacion obtenido con Claude Sonet 4.6.
    promt:
    Podrias entregarme una implementacion del algoritmo de ordenamiento de quicksort que ademas haga uso de la tecnica "Median of Three"
    para la seleccion del pivote (en c++)
*/
#include "quicksort.h"

// Median of Three: returns index of median value among arr[low], arr[mid], arr[high]
int medianOfThree(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid])
        std::swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        std::swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        std::swap(arr[mid], arr[high]);

    // arr[low] <= arr[mid] <= arr[high]; median is at mid
    // Place pivot at high-1 to keep it out of the partition zone
    std::swap(arr[mid], arr[high - 1]);
    return high - 1;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivotIdx = medianOfThree(arr, low, high);
    int pivot = arr[pivotIdx];

    int i = low;
    int j = high - 1;

    while (true) {
        while (arr[++i] < pivot);  // move right past elements < pivot
        while (arr[--j] > pivot);  // move left past elements > pivot
        if (i >= j) break;
        std::swap(arr[i], arr[j]);
    }

    // Restore pivot to its final position
    std::swap(arr[i], arr[high - 1]);
    return i;
}

void quicksort(std::vector<int>& arr, int low, int high) {
    // Use insertion sort for small subarrays (optimization)
    if (high - low < 10) {
        for (int i = low + 1; i <= high; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= low && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
        return;
    }

    int pivotIdx = partition(arr, low, high);
    quicksort(arr, low, pivotIdx - 1);
    quicksort(arr, pivotIdx + 1, high);
}

void quickSort(std::vector<int>& arr) {
    if (arr.size() > 1)
        quicksort(arr, 0, arr.size() - 1);
}
