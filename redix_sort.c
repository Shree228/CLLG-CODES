#include <stdio.h>
#include <stdlib.h>

// Get maximum value in array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting sort for a specific digit
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count[i] so that count[i] contains actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort main function
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    // Apply counting sort for every digit
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
