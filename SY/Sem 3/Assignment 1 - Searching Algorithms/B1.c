/*	a) Read the data from file'cities.txt' containing names of cities and their STD codes. Accept a 
	name of the city from user and use linear search to check whether the name is present in the 
	file and output the STD code, otherwise output “city not in the list”.*/

// Linear Search w. File Handling

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSearchtxt(char filename[], char cityname[]){
	FILE *fptr = fopen(filename,"r");
	if(fptr==NULL){
		printf("Error 00");
		return;
	}
	char city[100];
	int stdCode;
	int found=0;
	while(!feof(fptr)){
		fscanf(fptr,"%s %d",city,&stdCode);
		if(strcmp(city,cityname)==0){
			printf("City = %s, STD code = %d\n",city,stdCode);
			found=1;
			break;
		}
	}
	if(found!=1){
		printf("City not in the list\n");
	}
	fclose(fptr);
}
int main(){
	char cityName[100];
	printf("Enter City Name to search - ");
	scanf("%s",cityName);
	linearSearchtxt("cities.txt",cityName);
	return 0;
}
