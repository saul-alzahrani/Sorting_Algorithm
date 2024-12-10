#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define BLOCK_SIZE 16

int arr[ARRAY_SIZE], leftArray[ARRAY_SIZE / 2], rightArray[ARRAY_SIZE / 2];

// Merge Function with Loop Blocking
void merge_blocking(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        for (int b = 0; b < BLOCK_SIZE && i < n1 && j < n2; b++) {
            if (leftArray[i] <= rightArray[j])
                arr[k++] = leftArray[i++];
            else
                arr[k++] = rightArray[j++];
        }
    }

    while (i < n1)
        arr[k++] = leftArray[i++];
    while (j < n2)
        arr[k++] = rightArray[j++];
}

void merge_sort_blocking(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_blocking(left, mid);
        merge_sort_blocking(mid + 1, right);
        merge_blocking(left, mid, right);
    }
}

int main() {
    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 1000 + 1;

    printf("Unsorted array (first 10 elements):\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("...\n");

    printf("Sorting with Merge Sort with Loop Blocking...\n");
    merge_sort_blocking(0, ARRAY_SIZE - 1);

    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("...\n");

    return 0;
}
