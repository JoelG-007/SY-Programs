#include<stdio.h>
#define MAXSIZE 100
typedef struct{
	char data[MAXSIZE];
  	int top;
}STACK;
void inistack(STACK *ps){
	ps->top=-1;
}
void push(STACK*ps, char ch) {
	ps->data[++ps->top]=ch;
}
char pop(STACK *ps){
	return(ps->data[ps->top--]);
}
char peek(STACK *ps){
	return ps->data[ps->top];
}
int isempty(STACK *ps){
	return(ps->top==-1);
}
int isfull(STACK *ps){
	return(ps->top==MAXSIZE - 1);
}

