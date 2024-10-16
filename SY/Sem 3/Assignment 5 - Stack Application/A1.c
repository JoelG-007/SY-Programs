/*	a) Write a program that reverses a string of characters. The function should use a stack library 
	(cststack.h) of stack of characters using a static implementation of the stack.*/

#include<stdio.h>
#include<stdlib.h>
#include"cstStack.h"
void reverse(char str[20]){
	int i;
	STACK s;
	inistack(&s);
	for(i=0;str[i]!='\0';i++)
		push(&s,str[i]);
	i=0;
	while(!isempty(&s))
		str[i++]=pop(&s);
}
void main(){
	char str[]="hello";
	printf("\n\nThe original string is %s",str);
	reverse(str);
	printf("\nThe reversed string is %s\n\n",str);
}	
