#include <stdio.h>
#include <limits.h>


int find_max_crossing_subarray(int *,int,int,int);
int find_maximum_subarray(int *,int,int);

main()
{
	int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	printf("%d\n",find_maximum_subarray(a,0,15));
}

int find_max_crossing_subarray(int *a,int low,int mid,int high)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum,i;

	sum = 0;
	for (i = mid;i >= 0;i--) {
		sum += a[i];
		if (sum > left_sum) {
			left_sum = sum;
		}
	}
	sum = 0;
	for (i = mid+1;i <= high;i++) {
		sum += a[i];
		if (sum > right_sum) {
			right_sum = sum;
		}
	}
	return left_sum + right_sum;
}
int find_maximum_subarray(int *a,int low,int high)
{
	int mid;
	int max_sum,max_sum1,max_sum2;
	max_sum = max_sum1 = max_sum2 = INT_MIN;

	if (high == low) {
		return a[low];
	} else {
		mid = (low + high) / 2;
		max_sum1 = find_maximum_subarray(a,low,mid);
		max_sum2 = find_maximum_subarray(a,mid+1,high);
		max_sum = find_max_crossing_subarray(a,low,mid,high);
		
		if (max_sum >= max_sum1 && max_sum >= max_sum2)
			return max_sum;
		else if (max_sum1 >= max_sum && max_sum1 >= max_sum2)
			return max_sum1;
		else
			return max_sum2;
	}
}


