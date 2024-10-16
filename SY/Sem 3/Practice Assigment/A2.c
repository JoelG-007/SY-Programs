/*	Q2. Write a C program to calculate the sum of digits of a number using recursion. */

#include<stdio.h>
int sumOfDigits(int num){
	if(num==0){
		return 0;
	}else
		return(num%10)+sumOfDigits(num/10);
}
int main(){
	int n,sum=0;
	printf("Enter a number - ");
	scanf("%d",&n);
	sum=sumOfDigits(n);
	printf("Sum of %d is %d.\n",n,sum);
	return 0;
}
