/*	Q1. Write a function isEven, which accepts an integer as parameter and returns 1 if the number is even,
	and 0 otherwise. Use this function in main to accept n numbers and check if they are even or odd. */

#include<stdio.h>
int isEven(int a){
	return a%2==0?1:0;
}
int main(){
	int num;
	printf("Enter a number - ");
	scanf("%d",&num);
	if(isEven(num)){
		printf("%d is even.\n",num);
	}else{
		printf("%d is odd.\n",num);
	}
	return 0;
}
