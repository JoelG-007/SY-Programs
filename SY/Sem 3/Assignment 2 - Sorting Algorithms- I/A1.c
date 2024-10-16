/*	a) Sort a random array of n integers (accept the value of n from user) in ascending order by 
	using bubble sort algorithm. */

// Bubble Sort
#include<stdio.h>
#include<stdlib.h>
int i,j,temp;

void generate(int arr[], int n){
	for(i=0;i<n;i++)
		arr[i]=rand()%100;
}

void bubbleSort(int arr[], int n){
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void display(int arr[], int n, char message[10]){
	printf("%s sorting - \n",message);
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

int main(){
	int n;
	printf("How many elements? - ");
	scanf("%d",&n);
	int arr[n];
	generate(arr,n);
	display(arr,n,"Before");
	bubbleSort(arr,n);
	display(arr,n,"After");
}
