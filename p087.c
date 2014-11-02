#include <stdio.h>

int parent(int i);
int left(int i);
int right(int i);
void max_heapify(int *a,int i,int len);
void build_max_heap(int *a,int len);
void heapsort(int *a,int len);

main()
{
	int i;
	int a[10] = {32,54,12,7,4,34,67,12,33,10};
	heapsort(a,10);
//	max_heapify(a,2,10);
	//build_max_heap(a,10);
	for (i = 0;i < 10;i++)
		printf("%d  ",a[i]);
	printf("\n");
}

int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}
void max_heapify(int *a,int i,int len)
{
	int l,r,largest,heap_size;
	l = left(i);
	r = right(i);
	heap_size = len;
	if (l <= heap_size && a[l-1] > a[i-1])
		largest = l;
	else largest = i;
	if (r <= heap_size && a[r-1] > a[largest-1])
		largest = r;
	if (largest != i) {
		a[i-1] = a[i-1] ^ a[largest-1];
		a[largest-1] = a[i-1] ^ a[largest-1];
		a[i-1] = a[largest-1] ^ a[i-1];
		max_heapify(a,largest,len);
	}
}
void build_max_heap(int *a,int len)
{
	int heap_size,i;
	heap_size = len;
	for (i = len/2;i >= 1;i--)
		max_heapify(a,i,heap_size);
}
void heapsort(int *a,int len)
{
	int i,heap_size;

	heap_size = len;
	build_max_heap(a,heap_size);
	for (i = heap_size;i >= 2;i--) {
		a[0] = a[0] ^ a[i-1];
		a[i-1] = a[0] ^ a[i-1];
		a[0] = a[0] ^ a[i-1];
		heap_size--;
		max_heapify(a,1,heap_size);
	}
}
