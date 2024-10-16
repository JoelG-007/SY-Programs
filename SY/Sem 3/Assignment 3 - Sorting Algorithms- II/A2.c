/*	b) Sort a random array of n integers (create a random array of n integers) in ascending order 
	by using recursive Quick sort algorithm.*/

// Quick Sort

#include<stdio.h>
#include<stdlib.h>
int i,j;
void generate(int arr[], int n){
	int i;
	for(i=0;i<=n;i++)
		arr[i]=rand()%100;
}

int partition(int arr[],int lb, int ub){
	int down,up,temp, pivot;
	down=lb+1;
	up=ub+1;
	pivot=arr[lb];
	do{
		while((arr[down]<=pivot)&&(down<ub))
			down++;
		while((arr[up]>pivot)&&(up>lb))
                	up--;
		if(down<up){
			temp=arr[down];
			arr[down]=arr[up];
			arr[up]=temp;
		}
	}while(down<up);
	
	arr[lb]=arr[up];
	arr[up]=pivot;
	
	return up;
}

void quickSort(int arr[],int lb, int ub){
	if(lb<ub){
                j=partition(arr,lb,ub);
                quickSort(arr,lb,j-1);
                quickSort(arr,j+1,ub);
        }
}

void display(int arr[], int n, char message[10]){
	printf("%s sorting - \n",message);
	for(i=0;i<=n;i++){
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
	quickSort(arr,0,n-1);
	display(arr,n,"After");
  	return 0;
}

