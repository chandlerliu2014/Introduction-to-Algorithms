#include <stdio.h>

int main()
{
	int a[10] = {3,12,5,3,9,10,2,6,15,11}; //input array
	int b[10]; //output array
	int c[20]; //temp all element are not biger than 20
	
	int i,j;
	for (i = 0;i < 20;i++)
		c[i] = 0;
	for (j = 0;j < 10;j++)
		c[a[j]] += 1;
	for (i = 1;i < 20;i++)
		c[i] = c[i] + c[i-1];
	for (j = 9;j >= 0;j--) {
	[c[a[j]] - 1] = a[j];
		c[a[j]] -= 1;
	}
	for (i = 0;i < 10;i++)
		printf("%d ",b[i]);
	printf("\n");
	
}
