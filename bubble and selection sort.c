#include <stdio.h>

// Function to perform selection sort
void selectionSort(float arr[], int n) {
    int i, j, minIdx;
    float temp;

    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

// Function to perform bubble sort
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display top 5 scores
void displayTop5(float arr[], int n) {
    printf("\nTop 5 Scores:\n");

    // Start from end since array is sorted in ascending order
    for (int i = n - 1; i >= 0 && i >= n - 5; i--) {
        printf("%.2f%%\n", arr[i]);
    }
}

int main() {
    int n, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    float scores[n];

    // Input scores
    printf("Enter percentage scores of %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Score %d: ", i + 1);
        scanf("%f", &scores[i]);
    }

    // Choose sorting method
    printf("\nChoose sorting method:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        selectionSort(scores, n);
    } else if (choice == 2) {
        bubbleSort(scores, n);
    } else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    // Display sorted array
    printf("\nSorted Scores (Ascending):\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f%%\n", scores[i]);
    }

    // Display top 5
    displayTop5(scores, n);

    return 0;
}
