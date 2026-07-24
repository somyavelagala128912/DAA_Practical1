#include <iostream>
#include <vector>
#include <utility> // For std::swap

// Function to partition the array using the middle element as pivot
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        // Find element on the left that should be on the right
        do {
            i++;
        } while (arr[i] < pivot);

        // Find element on the right that should be on the left
        do {
            j--;
        } while (arr[j] > pivot);

        // If pointers cross, partitioning is complete
        if (i >= j) {
            return j;
        }

        std::swap(arr[i], arr[j]);
    }
}

// Main Quick Sort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // p is the partitioning index
        int p = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

// Utility function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {19, 48, 5, 27, 1, 14, 36, 12, 5, 2};
    
    std::cout << "Original array: ";
    printArray(data);

    quickSort(data, 0, data.size() - 1);

    std::cout << "Sorted array:   ";
    printArray(data);

    return 0;
}
