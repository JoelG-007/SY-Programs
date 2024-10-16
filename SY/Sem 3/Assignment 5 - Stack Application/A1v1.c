// Paalindrome

#include<stdio.h>
#include<stdlib.h>
#include"cstStack.h"
#include<string.h>
void reverse(char str[20]){
	int i;
	STACK s;
	char temp[20],rev[20];
	inistack(&s);
	for(i=0;str[i]!='\0';i++){
		temp[i]=str[i];
		push(&s,str[i]);
	}
	i=0;
	while(!isempty(&s))
		rev[i++]=pop(&s);
	displayStatus(rev,temp);
}
int displayStatus(char str1[20],char str2[20]){
	if(strcmp(str1,str2)==0)
		printf("\nIs a Palindrome\n\n");
	else
		printf("\nIsn't a Palindrome\n\n"); 
}	
void main(){
	char str[]="madam";
	printf("\nThe original string is %s",str);
	reverse(str);
}	

