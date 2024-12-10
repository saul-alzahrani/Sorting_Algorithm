#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function with loop interchange
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    // Outer loop iterates over the pivot and inner loop increments i when a smaller element is found
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[1000000];
    int n = sizeof(arr)/sizeof(arr[0]);

    // Initialize array with random numbers for demonstration
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Numbers between 0 and 999999
    }

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

