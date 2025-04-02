#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int divisionTable[TABLE_SIZE];
int midSquareTable[TABLE_SIZE];
int digitFoldingTable[TABLE_SIZE];


void initializeTables() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        divisionTable[i] = -1;
        midSquareTable[i] = -1;
        digitFoldingTable[i] = -1;
    }
}

// Division Method
int divisionMethod(int key) {
    return key % TABLE_SIZE;
}

// Mid Square Method
int midSquareMethod(int key) {
    int square = key * key;
    int mid = (square / 100) % 100; // Extract middle two digits manually
    return mid % TABLE_SIZE;
}

// Digit Folding Method
int digitFoldingMethod(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 10; // Adding pairs of digits
        key /= 10;
    }
    return sum % TABLE_SIZE;
}

void insertKey(int key, int (*hashFunction)(int), int table[], char* methodName) {
    int index = hashFunction(key);
    if (table[index] == -1) {
        table[index] = key; // Store key if slot is empty
        printf("%s: Key %d placed at index %d\n", methodName, key, index);
    } else {
        printf("%s: Collision detected for key %d at index %d\n", methodName, key, index);
    }
}

void displayTables() {
    int i;
    printf("\nFinal Hash Tables:\n");

    printf("\nDivision Method Table:\n");
    for (i = 0; i < TABLE_SIZE; i++)
        printf("[%d] -> %d\n", i, divisionTable[i]);

    printf("\nMid Square Method Table:\n");
    for (i = 0; i < TABLE_SIZE; i++)
        printf("[%d] -> %d\n", i, midSquareTable[i]);

    printf("\nDigit Folding Method Table:\n");
    for (i = 0; i < TABLE_SIZE; i++)
        printf("[%d] -> %d\n", i, digitFoldingTable[i]);
}

int main() {
    int n, key, i;

    printf("Enter the number of keys: ");
    scanf("%d", &n);

    initializeTables();

    for (i = 0; i < n; i++) {
        printf("\nEnter key %d: ", i + 1);
        scanf("%d", &key);

        insertKey(key, divisionMethod, divisionTable, "Division Method");
        insertKey(key, midSquareMethod, midSquareTable, "Mid Square Method");
        insertKey(key, digitFoldingMethod, digitFoldingTable, "Digit Folding Method");
    }

    displayTables();
    return 0;
}
