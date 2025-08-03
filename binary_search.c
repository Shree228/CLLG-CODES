#include <stdio.h>

// Binary Search Function
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return 1;  // Found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;  // Not found
}

int main() {
    int n, i, target;

    printf("Enter number of students who attended the training: ");
    scanf("%d", &n);

    int rollNumbers[n];

    printf("Enter %d roll numbers in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        printf("Roll number %d: ", i + 1);
        scanf("%d", &rollNumbers[i]);
    }

    printf("Enter roll number to search: ");
    scanf("%d", &target);

    if (binarySearch(rollNumbers, n, target)) {
        printf("Student with roll number %d attended the training.\n", target);
    } else {
        printf("Student with roll number %d did NOT attend the training.\n", target);
    }

    return 0;
}
