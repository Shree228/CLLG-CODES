#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return 1;  // Found
        }
    }
    return 0;  // Not found
}

int main() {
    int n, i, target;

    printf("Enter number of students who attended the training: ");
    scanf("%d", &n);

    int rollNumbers[n];

    printf("Enter roll numbers of students:\n");
    for (i = 0; i < n; i++) {
        printf("Roll number %d: ", i + 1);
        scanf("%d", &rollNumbers[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &target);

    if (linearSearch(rollNumbers, n, target)) {
        printf("Student with roll number %d attended the training.\n", target);
    } else {
        printf("Student with roll number %d did NOT attend the training.\n", target);
    }

    return 0;
}

