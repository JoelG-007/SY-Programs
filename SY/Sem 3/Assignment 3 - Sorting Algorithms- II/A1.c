/*	a) Sort a random array of n integers (accept the value of n from user) in ascending order by 
	using a recursive Merge sort algorithm.*/

// Merge Sort 

#include<stdio.h>
#include<stdlib.h>
int i,j;

void generate(int arr[], int n){		//Generation of 'n' numbers
	for(i=0;i<n;i++)
		arr[i]=rand()%100;
}
void merge(int arr[], int low, int mid, int high){	
	i=low, j=mid+1;
	int k=0, b[20]; 			// first half 
	while((i<=mid)&&(j<=high)){
		if(arr[i]<=arr[j]){
			b[k++]=arr[i++];
		}else{
			b[k++]=arr[j++];	
		}
	}
	while(i<=mid){				// second half
		b[k++]=arr[i++];
	}
	while(j<=high){
		b[k++]=arr[j++];
	}
	for(i=low,k=0;i<=high;i++,k++){
		arr[i]=b[k];
	}	
}
void mergeSort(int arr[],int low, int high){
        if(low<high){
                int mid=(low+high)/2;
                mergeSort(arr,low,mid);
                mergeSort(arr,mid+1,high);
                merge(arr,low,mid,high);
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
	mergeSort(arr,0,n-1);
	display(arr,n,"After");
	return 0;
}

