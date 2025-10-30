#include <iostream>
#include <vector>
using namespace std;

/*
 * BINARY SEARCH ALGORITHM
 * ------------------------
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * 
 * Binary Search finds a target value within a sorted array by 
 * repeatedly dividing the search range in half.
 */

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid integer overflow

        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16};
    int target = 10;

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Element " << target << " found at index " << index << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
