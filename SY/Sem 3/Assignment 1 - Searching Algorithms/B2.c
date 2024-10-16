/*	b) Read the data from file ‘sortedcities.txt’ containing sorted names of cities and their STD 
	codes. Accept a name of the city from user and use binary search to check whether the name is 
	present in the file and output the STD code, otherwise output “city not in the list”. */

// Binary Search w. File Handling

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cityDets{
	char city[100];
	int stdCode;
};

int binarySearchtxt(struct cityDets arr[], int n, char cityName[]){
	int start=0,end=n-1, cmp, mid;
	while(start<=end){
		mid=(end+start)/2;
		cmp=strcmp(arr[mid].city,cityName);
		if(cmp==0){
			return mid;
		}
		if(cmp<0){			// arr[mid]<cityName
			start=mid+1;
		}else{
			end=mid-1;
		}
	}
	return -1;
}

int readFile(char filename[], struct cityDets cities[]){
	FILE *fptr=fopen(filename,"r");
	if(fptr==NULL){
		printf("Error 00\n");
		return;
	}
	int n=0;
	while(!feof(fptr)){
		fscanf(fptr,"%s %d",cities[n].city, &cities[n].stdCode);
		n++;
	}
	fclose(fptr);
	return n;
}

int main(){
	int posi,cnt;
	char cityName[100];
	struct cityDets cities[100];
	cnt=readFile("sortedCities.txt",cities);
	printf("Enter a city to search - ");
	scanf("%s",cityName);
	posi=binarySearchtxt(cities,cnt,cityName);
	if(posi!=-1){
		printf("City - %s, STD - %d\n",cities[posi].city,cities[posi].stdCode);
	}else{
		printf("City not in the list\n");
	}
	return 0;
}
