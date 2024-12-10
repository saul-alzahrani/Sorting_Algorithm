#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        for (int j = i; j > 0; j--)  // Loop interchange applied here
            heapify(arr, j, 0);
    }
}

void printFirst10(int arr[], int n) {
    int limit = n < 10 ? n : 10;
    for (int i = 0; i < limit; i++)
        printf("%d ", arr[i]);
    if (n > 10)
        printf("... (only first 10 shown)");
    printf("\n");
}

void generateRandomArray(int arr[], int n, int max_val) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_val;
    }
}

int main() {
    const int N = 1000000;
    const int MAX_VAL = 1000;
    int arr[N];
    double start, finish, elapsed;

    generateRandomArray(arr, N, MAX_VAL);

    printf("First 10 unsorted values:\n");
    printFirst10(arr, N);

    GET_TIME(start);
    heapSort(arr, N);
    GET_TIME(finish);

    elapsed = finish - start;

    printf("\nFirst 10 sorted values:\n");
    printFirst10(arr, N);

    printf("\nExecution time: %e seconds\n", elapsed);

    return 0;
}
