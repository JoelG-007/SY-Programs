/*	c) Write a program to convert an infix expression to its equivalent postfix notation and 
	evaluate. Consider usual precedence’s of operators. Use stack library of stack of characters 
	using static implementation.*/

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
			case'(':push(&s,ch);
				break;
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

int evaluate(char postfix[20]){
	STACK s;
	int i, value, operand1, operand2;
	inistack(&s);
	for(i=0;postfix[i]!='\0';i++){
		switch(postfix[i]){
			case '+':operand2=pop(&s);
				operand1=pop(&s);
				push(&s,operand1 + operand2);
				break;
			case '-':operand2=pop(&s);
                                operand1=pop(&s);
                                push(&s,operand1 - operand2);
				break;
			case '*':operand2=pop(&s);
                                operand1=pop(&s);
                                push(&s,operand1 * operand2);
				break;
			case '/':operand2=pop(&s);
                                operand1=pop(&s);
                                push(&s,operand1 / operand2);
				break;
			case '%':operand2=pop(&s);
                                operand1=pop(&s);
                                push(&s,operand1 % operand2);
				break;
			case '^':
			case '$':operand2=pop(&s);
                                operand1=pop(&s);
                                push(&s,operand1^operand2);
				break;
			default:
				printf("Enter value of %c - ",postfix[i]);
				scanf("%d",&value);
				push(&s,value);
		}
	} 
	return pop(&s);	
}
void main(){
  	char infix[20], postfix[20];
	float ans;
	printf("\nEnter the infix expression - ");
	scanf("%s",infix);
	convert(infix,postfix);
	printf("\nThe postfix string is %s\n",postfix);
	/*
	printf("\nEnter Postfix expression - ");
  	scanf("%s",&postfix);
	*/
	ans=evaluate(postfix);		
	printf("The answer of %s = %.2f",postfix,ans); 
}
