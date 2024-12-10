#include <stdio.h>
#include <stdlib.h>

// Quicksort function with inlining
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition inlined
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                // Swap inlined
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
        int t = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = t;
        int pi = (i + 1);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[1000];
    int n = sizeof(arr)/sizeof(arr[0]);

    // Initialize array with random numbers for demonstration
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Numbers between 0 and 999
    }

    printf("Unsorted array:\n");
    for (int i = 0; n != 0 && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; n != 0 && i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

