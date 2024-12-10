#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BLOCK_SIZE 64

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function with loop blocking
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Loop blocking for quicksort
void blockedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition with loop blocking
        #pragma omp parallel sections
        {
            #pragma omp section
            blockedQuickSort(arr, low, pi - 1);
            #pragma omp section
            blockedQuickSort(arr, pi + 1, high);
        }
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
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    blockedQuickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

