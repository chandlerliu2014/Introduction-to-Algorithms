#include <stdio.h>
#include <limits.h>

int sort(int *,int,int);

main()
{
	int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	printf("%d\n",sort(a,0,15));
}

int sort(int *a,int low,int high)
{
	int i,j,k,sum,max_sum;
	
	max_sum = INT_MIN;

	for (i = low;i <= high;i++) {
		for (j = low+1;j <= high;j++) {
			sum = 0;
			for (k = i;k <= j;k++) {
				sum += a[k];
			}
			if (sum > max_sum)
				max_sum = sum;
		}
	}
	return max_sum;
}
