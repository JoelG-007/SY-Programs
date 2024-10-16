/*	Q1. Write a function isEven, which accepts an integer as parameter and returns 1 if the number is even,
	and 0 otherwise. Use this function in main to accept n numbers and check if they are even or odd. */

#include<stdio.h>
#include<stdlib.h>
int isEven(int a){
	return a%2==0?1:0;	
}
int main(){
	int i,lim;
	int *arr;
	printf("Enter the limit - ");
	scanf("%d",&lim);
	arr=(int*)malloc(lim*sizeof(int));
	if(arr==NULL){
		printf("Memory allocation failed");
		return 1;
	}
	printf("Enter %d numbers - \n",lim);
	for(i=0;i<lim;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<lim;i++){
		if(isEven(arr[i])){
			printf("%d is Even.\n",arr[i]);
		}else{
			printf("%d is Odd.\n",arr[i]);
		}
	}
	free(arr);
	return 0;
}
