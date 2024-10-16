/*	a) Create a random array of n integers. Accept a value x from user and write a function to 
	implement linear search algorithm to check whether the number is present in the array or not 
	and output the position if  the number is present.*/
	
// Linear Search w. array

#include<stdio.h>
#include<stdlib.h>
int i;
void generate(int a[], int n){
	for(i=0;i<n;i++){
		a[i]=rand()%100;
	}
}
int linearSearch(int arr[], int n, int key){
	for(i=0;i<n;i++){
		if(arr[i]==key){
			return i;
		}
	}	
	return -1;
}
void display(int a[],int n){
	printf("\nElements - ");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
int main(){
	int n, key, posi;
	printf("Enter limit - ");
	scanf("%d",&n);
        int a[n];
	generate(a,n);
	display(a,n);
	printf("\nEnter a number to search - ");
	scanf("%d",&key);
	posi=linearSearch(a,n,key);
	if(posi!=-1)
		printf("Number found at %d\n",posi+1);
	else
		printf("%d not found",key);
	return 0;
}
