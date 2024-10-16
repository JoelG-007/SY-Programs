/*	c) Sort a random array of n integers (accept the value of n from user) in ascending order by 
	using selection sort algorithm. */

// Selection Sort

#include<stdio.h>
#include<stdlib.h>
int i,j;

void generate(int arr[], int n){
	for(i=0;i<n;i++)
		arr[i]=rand()%100;
}

void selectionSort(int arr[], int n){
	int temp,current,pos,smallest;
	for(current=0;current<n-1;current++){
		smallest=arr[current];
		pos=current;
		for(i=current+1;i<=n-1;i++)
			if(arr[i]<smallest){
				smallest=arr[i];
				pos=i;
			}
			temp=arr[current];
			arr[current]=arr[pos];
			arr[pos]=temp;
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
	selectionSort(arr,n);
	display(arr,n,"After");
}




