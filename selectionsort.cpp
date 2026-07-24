#include <iostream>
#include <vector>

// Function to perform Selection Sort
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    // Move the boundary of the unsorted subarray one by one
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted array
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    printArray(data);

    selectionSort(data);

    std::cout << "Sorted array: ";
    printArray(data);

    return 0;
}
