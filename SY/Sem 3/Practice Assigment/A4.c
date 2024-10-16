/*	Q4. Write a C program to count the number of occurrence of element in an array.
	Note: Accept element to be count from the user. */

#include<stdio.h>
#include<stdlib.h>
int occur(int a[], int lim, int key){
	int counter=0, i;
	for(i=0;i<lim;i++){
		if(a[i]==key){
			counter++;
		}
	}
	return counter;
}
int main(){
	int i, lim, find, cnt=0;
	int *arr;
	printf("Enter limit - \n");
	scanf("%d",&lim);
	arr=(int*)malloc(lim*sizeof(int));
	printf("Enter %d numbers - \n",lim);
	for(i=0;i<lim;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter an element to count - \n");
	scanf("%d",&find);
	cnt=occur(arr, lim, find);
	printf("\n%d was found %d times.\n\n",find,cnt);
}
