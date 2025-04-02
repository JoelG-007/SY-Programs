#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 1;

    while (hashTable[index] != -1) { // Check for collision
        printf("Collision at index %d\n", index);
        index = (hashFunction(key) + i * i) % TABLE_SIZE; // Quadratic probing formula
        i++;

        if (i == TABLE_SIZE) { // Table is full
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Key %d inserted at index %d\n", key, index);
}

void search(int key) {
    int index = hashFunction(key);
    int i = 1;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (hashFunction(key) + i * i) % TABLE_SIZE; // Quadratic probing search
        i++;

        if (i == TABLE_SIZE) break;
    }

    printf("Key %d not found in hash table\n", key);
}

void delete(int key) {
    int index = hashFunction(key);
    int i = 1;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            hashTable[index] = -1; // Mark as deleted
            printf("Key %d deleted from index %d\n", key, index);
            return;
        }
        index = (hashFunction(key) + i * i) % TABLE_SIZE;
        i++;

        if (i == TABLE_SIZE) break;
    }

    printf("Key %d not found in hash table\n", key);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1)
            printf("[%d] -> EMPTY\n", i);
        else
            printf("[%d] -> %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;

    initializeTable();

    do {
        printf("\nMenu:\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
