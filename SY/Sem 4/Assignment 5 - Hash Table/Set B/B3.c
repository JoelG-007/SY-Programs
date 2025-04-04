/*
    Write a program to implement hash table using chaining (Use linked list).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

#define TABLE_SIZE 10
Node* chain[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertChaining(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = chain[index];
    chain[index] = newNode;
    printf("%d inserted at index %d\n", key, index);
}

void displayChaining(){
  int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        Node* temp = chain[i];
        printf("[%d]", i);
        while (temp) {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }
}

int main(){
  int i;
    for (i = 0; i < TABLE_SIZE; i++) chain[i] = NULL;
    int choice, key;
    do {
        printf("\n1. Insert (Chaining)\n2. Display (Chaining)\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertChaining(key);
                break;
            case 2:
                displayChaining();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}
