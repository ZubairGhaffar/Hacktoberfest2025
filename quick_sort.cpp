#include <iostream>
#include <vector>
using namespace std;

/*
 * QUICK SORT ALGORITHM
 * ---------------------
 * Time Complexity: O(n log n) average, O(n^2) worst
 * Space Complexity: O(log n)
 * 
 * Quick Sort selects a pivot, partitions elements, and recursively sorts each side.
 */

// Partition function to place pivot at correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Pointer for smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // If element smaller than pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
