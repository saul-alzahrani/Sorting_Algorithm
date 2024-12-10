#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int arr[ARRAY_SIZE], leftArray[ARRAY_SIZE / 2], rightArray[ARRAY_SIZE / 2];

// Merge Function with Loop Interchange
void merge_interchange(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    for (k = left; k <= right; k++) {
        if (i >= n1)
            arr[k] = rightArray[j++];
        else if (j >= n2)
            arr[k] = leftArray[i++];
        else if (leftArray[i] <= rightArray[j])
            arr[k] = leftArray[i++];
        else
            arr[k] = rightArray[j++];
    }
}

// Merge Sort with Loop Interchange
void merge_sort_interchange(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_interchange(left, mid);
        merge_sort_interchange(mid + 1, right);
        merge_interchange(left, mid, right);
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

    printf("Sorting with Merge Sort with Loop Interchange...\n");
    merge_sort_interchange(0, ARRAY_SIZE - 1);

    printf("Sorted array (first 10 elements):\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("...\n");

    return 0;
}
