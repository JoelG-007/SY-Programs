/*	b) Sort a random array of n integers (create a random array of n integers) in ascending order by 
	using insertion sort algorithm. */

// Insertion Sort

#include<stdio.h>
#include<stdlib.h>
int i,j;

void generate(int arr[], int n){
	for(i=0;i<n;i++)
		arr[i]=rand()%100;
}

void insertionSort(int arr[], int n){
	int key;
	for(i=1;i<n;i++){
		key=arr[i];
		for(j=i-1;j>=0;j--){
			if(key<arr[j])
				arr[j+1]=arr[j];
			else
				break;
		}
		arr[j+1]=key;
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
	insertionSort(arr,n);
	display(arr,n,"After");
}
