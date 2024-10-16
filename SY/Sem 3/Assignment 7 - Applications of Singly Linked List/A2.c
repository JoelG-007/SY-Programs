/*  b) Write a program that adds two single variable polynomials. Each polynomial should be 
    represented as a list with linked list implementation. */

#include<stdio.h>
#include<stdlib.h>
#include"polynomialOperations.h"
int main(){
    POLY *p1, *p2, *p3;
    p1=(POLY *)malloc(sizeof(POLY));
    p1->next = NULL;
    p2=(POLY *)malloc(sizeof(POLY));
    p2->next = NULL;
    p3=(POLY *)malloc(sizeof(POLY));
    p3->next = NULL;
    create(p1);
    display(p1);
    create(p2);
    display(p2);
    add(p1, p2, p3);
    printf("\nThe addition is: ");
    display(p3);
    return 0;
}