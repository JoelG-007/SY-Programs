/*	Q5. Write a C program to swap two integers using call by values and call by reference. */

#include<stdio.h>
void swapV(int x, int y){
	int temp;
	temp=x;
	x=y;
	y=temp;
	printf("\nIn function (Swap by value) - x=%d\ty=%d",x,y);
}
void swapR(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main(){
	int x=10, y=5;
	printf("\nBefore swapping - x=%d\ty=%d",x,y);
	swapV(x,y);
        printf("\nIn main (Swap by value) - x=%d\ty=%d",x,y);
	swapR(&x,&y);
	printf("\nSwap by reference - x=%d\ty=%d\n",x,y);
	return 0;
}
