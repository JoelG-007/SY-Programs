/*	Q3. Write a C program to accept n numbers in an array and display the largest and smallest values. Write
	separate functions. */

#include<stdio.h>
#include<stdlib.h>
int isSmall(int a[], int lim){	// function to find smallest in the array
	int small=a[0],i;
	for(i=0;i<lim;i++){
		if(a[i]<small){
			small=a[i];
		}
	}
	return small;			
}
int isLarge(int a[], int lim){	// function to find largest in the array
        int large=a[0],i;
        for(i=0;i<lim;i++){
                if(a[i]>large){
                        large=a[i];
                }
        }
	return large;
}
int main(){
	int i,min,max,lim;
	int *arr;
	printf("Enter the limit - ");	// size of the array
	scanf("%d",&lim);
	arr=(int*)malloc(lim*sizeof(int));	// allocating size for the aray
	if(arr==NULL){
		printf("Memory allocation failed.");
		return 1;
	}
	printf("Enter %d elements - \n",lim);	// data entry for n elements
	for(i=0;i<lim;i++){
		scanf("%d",&arr[i]);
	}
	min=isSmall(arr,lim);
	max=isLarge(arr,lim);
	printf("\n\tLargest number - %d\n\tSmallest number - %d\n\n",max,min);
	free(arr);
	return 0;
}
