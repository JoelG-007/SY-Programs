// Recursive Bubble Sort 

#include <stdio.h>
#include <stdlib.h>

void generate(int arr[], int n){
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }
}

void bubbleSortRecursive(int arr[], int n){
    if (n <= 1) {
        return;
    }

    for (int j = 0; j < n - 1; j++){
        if (arr[j] > arr[j + 1]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }

    bubbleSortRecursive(arr, n - 1);
}

void display(int arr[], int n, char message){
    printf("%s sorting - \n", message);
    for (int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("How many elements? - ");
    scanf("%d", &n);
    
    int arr[n];
    generate(arr, n);
    display(arr, n, "Before");
    bubbleSortRecursive(arr, n);
    display(arr, n, "After");

    return 0;
}
