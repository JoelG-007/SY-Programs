#include<stdio.h>
#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];
  	int top;
}STACK;
void inistack(STACK *ps){
	ps->top=-1;
}
void push(STACK *ps, int num) {
	ps->data[++ps->top]=num;
}
int pop(STACK *ps){
	return(ps->data[ps->top--]);
}
int peek(STACK *ps){
	return ps->data[ps->top];
}
int isempty(STACK *ps){
	return(ps->top==-1);
}
int isfull(STACK *ps){
	return(ps->top==MAXSIZE - 1);
}
int priority(char ch){
	switch(ch){
		case'(':return 0;
		case'+':
		case'-':return 1;
		case'*':
		case'/':
		case'%':return 2;
		case'^':
		case'$':return 3;
	}
	return 0;
}


  

