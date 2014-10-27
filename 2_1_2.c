#include <stdio.h>

void insertion_sort(int *,int);

main()
{
	int i;
	int a[10] = {13,45,23,546,34,34,63,2,7,43};
	insertion_sort(a,10);
	for (i = 0;i < 10;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void insertion_sort(int *a,int n)
{
	int i,j,key;

	for (j = 1;j < n;j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] < key) {
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}
