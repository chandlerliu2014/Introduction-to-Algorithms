#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void merge_sort(int *,int,int);

main()
{
	int a[10] = {3,6,34,54,32,45,23,67,3,54};
	int i;
	merge_sort(a,0,9);
	for(i = 0;i < 10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void merge_sort(int *a,int n1,int n2)
{
	int q;
	void merge(int *,int,int,int);
	
	if (n1 < n2) {
		q = (n1 + n2) / 2;
		merge_sort(a,n1,q);
		merge_sort(a,q+1,n2);
		merge(a,n1,q,n2);
	}
}

void merge(int *a,int p,int q,int r)
{
	int n1,n2,i,j,k;
	int *L,*R;

	n1 = q - p + 1;
	n2 = r - q;
	L = malloc((n1 + 1) * sizeof(int));
	R = malloc((n2 + 1) * sizeof(int));
	for (i = 0;i < n1;i++)
		L[i] = a[p+i];
	for (j = 0;j < n2;j++)
		R[j] = a[q+j+1];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	for (i = 0,j = 0,k = p;k <= r;k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}
	free(L);
	free(R);
}
