#include <stdio.h>
#include <limits.h>

int line_sort(int *,int,int);

main()
{
	int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	printf("%d\n",line_sort(a,0,15));
}

int line_sort(int *a,int low,int high)
{
	int i,sum,max_sum;
	int index_start,index_end;

	sum = 0;
	max_sum = INT_MIN;
	for (i = low;i <= high;i++) {
		sum += a[i];
		if (sum < 0) {
			sum = 0;
			index_start = i + 1;
		}
		if (sum > max_sum) {
			max_sum = sum;
			index_end = i;
		}
	}
	if (max_sum == 0) {
		max_sum = a[low];
		for (i = low + 1;i <= high;i++) {
			if (max_sum < a[i]) {
				max_sum = a[i];
				index_start = index_end = i;
			}
		}
	}

	printf("index_start:%d, index_end:%d \n",index_start,index_end);

	return max_sum;
}
