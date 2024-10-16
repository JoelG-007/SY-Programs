// Recursive Binary Search

#include <stdio.h>
#include <stdlib.h>

void accept(int a[], int n) {
    printf("Enter %d elements - \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int binarySearch(int arr[], int start, int end, int key) {
    if (start > end) {
        return -1; // Base case: key not found
    }

    int mid = (start + end) / 2;

    if (arr[mid] == key) {
        return mid; // Key found
    }

    if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, end, key); // Search in the right half
    } else {
        return binarySearch(arr, start, mid - 1, key); // Search in the left half
    }
}

int main() {
    int n, posi, key;
    printf("How many elements? - (In ascending order) ");
    scanf("%d", &n);
    int a[n];
    accept(a, n);
    
    printf("\nEnter a number to search - ");
    scanf("%d", &key);
    
    posi = binarySearch(a, 0, n - 1, key);
    
    if (posi != -1) {
        printf("Number found at position %d\n", posi + 1);
    } else {
        printf("%d not found\n", key);
    }

    return 0;
}
