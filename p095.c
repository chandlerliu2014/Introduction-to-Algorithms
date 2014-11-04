#include <stdio.h>

void quicksort(int *a,int p,int r);
int partition(int *a,int p,int r);
main()
{
	int a[12] = {2,8,23,7,1,3,5,34,64,6,32,4};
	int i;
	//printf("%d\n",partition(a,1,8));
	quicksort(a,1,12);
	for (i = 0;i < 12;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
void quicksort(int *a,int p,int r)
{
	int q;//,partition(int *a,int p,int r);
	if (p < r) {
		q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int partition(int *a,int p,int r)
{
	int x,i,j;
	int temp;
	x = a[r-1];
	i = p - 1;
	for (j = p-1;j < r-1;j++) {
		if (a[j] <= x) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
		}
	}
	temp = a[i];
	a[i] = a[r-1];
	a[r-1] = temp; 
	return i+1;
}
