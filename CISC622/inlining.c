#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        int largest = i;
        while (1) {
            int left = 2 * largest + 1;
            int right = 2 * largest + 2;
            int newLargest = largest;

            if (left < n && arr[left] > arr[newLargest])
                newLargest = left;

            if (right < n && arr[right] > arr[newLargest])
                newLargest = right;

            if (newLargest == largest)
                break;

            int temp = arr[largest];
            arr[largest] = arr[newLargest];
            arr[newLargest] = temp;

            largest = newLargest;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int largest = 0;
        int size = i;
        while (1) {
            int left = 2 * largest + 1;
            int right = 2 * largest + 2;
            int newLargest = largest;

            if (left < size && arr[left] > arr[newLargest])
                newLargest = left;

            if (right < size && arr[right] > arr[newLargest])
                newLargest = right;

            if (newLargest == largest)
                break;

            temp = arr[largest];
            arr[largest] = arr[newLargest];
            arr[newLargest] = temp;

            largest = newLargest;
        }
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
