/*	Q7. Write a menu driven program in C using array of Structure
	a) Create a structure named employee(emp_code, ename, salary)
	b) Accept the details of 5 Employees from user and perform the following operations using function.
		i.Search by emp_code
		ii. Display all Employee details
		iii. Display Details of employee having Salary > 20000*/

#include<stdio.h>
# define EMPS 5
int i;
struct employee{
	int emp_code;
	char ename[50];
	float salary;
};
void accept(struct employee emp[], int emp_num){
	printf("Enter %d Employees deatails - ", emp_num);
	for(i=0;i<emp_num;i++){
		printf("\nEmployee %d",i+1);
		printf("\nName - ");
		scanf("%s",emp[i].ename);
		printf("Employee code - ");
		scanf("%d",&emp[i].emp_code);
		printf("Salary - ");
		scanf("%f",&emp[i].salary);
	}
}
int empCode_Search(struct employee emp[], int codeCMP, int emp_num){
	int flag=0;
	for(i=0;i<emp_num;i++){
		if(emp[i].emp_code==codeCMP){
			return i;
		}
	}
	return -1;	
}
void displayDets(struct employee emp[], int emp_num){
	for(i=0;i<emp_num;i++){
		printf("----------------------------");
		printf("\nName - %s\nEmployee Code - %d\nSalary %.2f",emp[i].ename,emp[i].emp_code,emp[i].salary);
	}
	return;
}
int salaryDisplay(struct employee emp[], int range, int emp_num){
	for(i=0;i<emp_num;i++){
		if(emp[i].salary==range){
			return i;
		}
	}
	return -1;
}

int main(){
	int range, choice, codeS, posi;
	struct employee emp[EMPS];
	accept(emp,EMPS);
	do{
		printf("\n1.Search by empcode - \n2.Display All Details - \n3.Salary display by range - \n4.Exit\n\tEnter choice (Number) - ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("\nEnter employee code to search - ");  
				scanf("%d",&codeS);
				posi=empCode_Search(emp,codeS,EMPS);
				if(posi!=-1)
					printf("\nName - %s\nEmployee Code - %d\nSalary %.2f",emp[posi].ename,emp[posi].emp_code,emp[posi].salary);
				else
					printf("\nEmployee does'nt exist.");
				break;
			case 2: printf("\nDisplaying all details - \n");
				displayDets(emp,EMPS);
				break;
			case 3: printf("\nEnter salary range - ");
				scanf("%f",&range);
				posi=salaryDisplay(emp,range,EMPS);
				if(posi!=-1)
                                        printf("\nName - %s\nEmployee Code - %d\nSalary %.2f",emp[posi].ename,emp[posi].emp_code,emp[posi].salary);
                                else
                                        printf("\nEmployee does'nt exist.");
                                break;
			case 4: printf("\n\t\t@@@ EXITING PROGRAM @@@");
				break;
		}
	}while(choice!=4);	
	return 0;
}

