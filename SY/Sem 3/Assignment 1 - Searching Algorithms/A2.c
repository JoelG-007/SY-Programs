/*	b) Accept n sorted values in array from user. Accept a value x from user and write a function 
	to implement binary search algorithm to check whether the number is present in sorted array 
	or not and output the position if the number is present.*/

// Binary search w. array

#include<stdio.h>
#include<stdlib.h>
int i;
void accept(int a[], int n){
	printf("Enter %d elements - \n",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	return;
}
int binarySearch(int arr[],int n,int key){
	int start=0,end=n-1,mid=0;
	while(start<=end){
		mid=(end+start)/2;
		if(arr[mid]==key){
			return mid;
		}
		if(arr[mid]<key){
			start=mid+1;
		}else{
			start=mid-1;
		}
	}
	return -1;
}
int main(){
	int n,posi,key;
	printf("How many elements? - (In ascending order)");
	scanf("%d",&n);
	int a[n];
	accept(a,n);
	printf("\nEnter a number to search - ");
	scanf("%d",&key);
	posi=binarySearch(a,n,key);
	if(posi!=-1)
		printf("Number found at postion %d\n",posi+1);
	else
		printf("%d not found",key);
	return 0;
}
