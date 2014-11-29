#include <stdio.h>
#define NUM 10


void counting_sort(int a[],int b[],int c[],int atemp[]);
int main()
{
	int i;
	int j;

	int a[10] = {326,54,512,13,9,71,92,61,53,19}; //input array
	int atemp[10];
	int b[10]; //output array
	int c[10]; //temp all element are not biger than 20
	
	// The first counting_sort
	for (i = 0;i < NUM;i++) 
		atemp[i] = a[i] % 10;
	counting_sort(atemp,b,c,a);
	for (i = 0;i < NUM;i++)
		a[i] = b[i];

	// The second counting_sort
	for (i = 0;i < NUM;i++) 
		atemp[i] = a[i] / 10 % 10;
	counting_sort(atemp,b,c,a);
	for (i = 0;i < NUM;i++)
		a[i] = b[i];
	
	for (i = 0;i < NUM;i++)
		atemp[i] = a[i] / 100 % 10;
	counting_sort(atemp,b,c,a);
		
	for (i = 0;i < NUM;i++)
		printf(" %d ",b[i]);
	printf("\n");
	
	
}

void counting_sort(int a[],int b[],int c[],int atemp[])
{
	int i,j;
	for (i = 0;i < NUM;i++)
		c[i] = 0;
	for (j = 0;j < NUM;j++)
		c[a[j]] += 1;
	for (i = 1;i < NUM;i++)
		c[i] = c[i] + c[i-1];
	for (j = 9;j >= 0;j--) {
		b[c[a[j]] - 1] = atemp[j];
		c[a[j]] -= 1;
	}
}
