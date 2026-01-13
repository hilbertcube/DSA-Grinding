#include "headers.hpp"

// This function takes the last element as pivot, places
// the pivot element at its correct position in sorted
// array, and places all smaller elements to left of pivot
// and all greater elements to right of pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);    // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> data = {10, 80, 30, 90, 40, 50, 70};
    
    cout << "Original array: " << data << endl;

    quickSort(data);

    cout << "Sorted array:   " << data << endl;

    return 0;
}