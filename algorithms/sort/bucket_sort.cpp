#include "headers.hpp"


void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets (using vector of vectors)
    std::vector<float> buckets[n];

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        // Calculate the bucket index: 
        // Multiplying by n gives an index from 0 to n-1 if values are in [0.0, 1.0)
        int bucketIndex = static_cast<int>(n * arr[i]);
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3. Sort individual buckets using a standard sorting algorithm
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

int main() {
    // Example input: uniformly distributed float numbers between 0.0 and 1.0
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array before Sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << std::fixed << std::setprecision(2) << arr[i] << " ";
    }
    std::cout << std::endl;

    bucketSort(arr, n);

    std::cout << "Array after Sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << std::fixed << std::setprecision(2) << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}