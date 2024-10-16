/*	b) Write a program to convert an infix expression to its equivalent postfix notation. Consider 
	usual precedence’s of operators. Use stack library of stack of characters using static 
	implementation.*/

#include<stdio.h>
#include<stdlib.h>
#include"expStack.h"
void convert(char infix[20], char post[20]){
	int i,j=0;
	char ch, ch1;
	STACK s;
	inistack(&s);
	for(i=0;infix[i]!='\0';i++){
		ch=infix[i];
		switch(ch){
			case'(':
			case'+':
			case'-':
			case'*':
			case'/':
			case'%':
			case'^':
			case'$':
				while(!isempty(&s)&&(priority(peek(&s))>=priority(ch)))
					post[j++]=pop(&s);
				push(&s,ch);
				break;
			case')':
				while((ch=pop(&s))!='(')
					post[j++]=ch;
					break;
			default:post[j++]=ch;
		}
	}
	while(!isempty(&s))
		post[j++]=pop(&s);
	post[j]='\0';
}

void main(){
	char infix[20], postfix[20];
	printf("\nEnter the infix expression - ");
	scanf("%s",infix);
	convert(infix,postfix);
	printf("\nThe postfix string is %s\n",postfix);
}
