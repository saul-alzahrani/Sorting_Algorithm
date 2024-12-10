#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Static arrays for temporary storage
int arr[ARRAY_SIZE], leftArray[ARRAY_SIZE / 2], rightArray[ARRAY_SIZE / 2];

// Merge Sort with Procedure Inlining
void merge_sort_inlining(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort both halves
        merge_sort_inlining(left, mid);
        merge_sort_inlining(mid + 1, right);

        // Inlined merging logic
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            leftArray[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArray[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        // Merge both halves inlined
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j])
                arr[k++] = leftArray[i++];
            else
                arr[k++] = rightArray[j++];
        }

        // Copy remaining elements from leftArray
        while (i < n1)
            arr[k++] = leftArray[i++];

        // Copy remaining elements from rightArray
        while (j < n2)
            arr[k++] = rightArray[j++];
    }
}

int main() {
    srand(time(0));

    // Initialize the array with random integers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000 + 1;  // Random numbers from 1 to 1000
    }

    // Print the first 10 elements of the unsorted array
    printf("Unsorted array (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("...\n");

    // Perform merge sort with procedure inlining
    printf("Sorting with Merge Sort with Loop Procedure Inlining...\n");
    merge_sort_inlining(0, ARRAY_SIZE - 1);

    // Print the first 10 elements of the sorted array
    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("...\n");

    return 0;
}
