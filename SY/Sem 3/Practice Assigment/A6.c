/*	Q6. Write a C program using array of Structure.
	a) Create a structure named, student(rollno, name,marks,perc).
	b) Accept details of 5 students(rollno,name,(marks of 5 subjects for each student ))
	c) Calculate percentage of students and display the details in a proper format.
		Roll No 	Name of Student 	Marks 	Percentage */

#include<stdio.h>
# define NUM_STUDENTS 5
# define NUM_SUBJECTS 5

struct student{
	int rollno;
	char name[50];
	int marks[NUM_SUBJECTS];
	float perc;
};
void acceptDets(struct student students[], int num_studs){
	int i,j;
	for(i=0;i<num_studs;i++){
		printf("\n\tStudent %d - \n",i+1);
		printf("Name - ");
		scanf("%s",students[i].name);
		printf("Roll number - ");
		scanf("%d",&students[i].rollno);
		printf("Marks of %d Subjects - \n",NUM_SUBJECTS);
		for(j=0;j<NUM_SUBJECTS;j++){
			printf("Subject %d - ",j+1);
			scanf("%d",&students[i].marks[j]);
		}
	}
}
void displayDets(struct student students[], int num_studs){
	int i,j;
	printf("\n\n\tEntered Details - ");
	printf("\n---------------------------------------------------------");
	printf("\n|Roll number\t|Name\t|Percentage\t");
	for(i=0;i<num_studs;i++){
		printf("\n|\t%d\t|%s\t|%.2f",students[i].rollno,students[i].name,students[i].perc);
		printf("\n\tMarks -");
		for(j=0;j<NUM_SUBJECTS;j++){
			printf("\n\tSubject(%d) - %d",j+1,students[i].marks[j]);
		}
	printf("\n---------------------------------------------------------");
	}	
}
void calcPerc(struct student students[], int num_studs){
	int i,j,total;
	for(i=0,total=0;i<num_studs;i++){
		for(j=0;j<NUM_SUBJECTS;j++){
			total+=students[i].marks[j];
		}
	students[i].perc=((float)total/5);
	}	
}
int main(){
	struct student students[NUM_STUDENTS];
	acceptDets(students,NUM_STUDENTS);
	calcPerc(students,NUM_STUDENTS);
	displayDets(students,NUM_STUDENTS);
	return 0;
}
