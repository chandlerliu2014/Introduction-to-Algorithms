//queue1.c

#include <stdlib.h>
#include <stdio.h>

static int *q;
static int N,head,tail;

void queue_init(int maxN)
{
	q = malloc((maxN + 1) * sizeof(int));
	N = maxN + 1;
	head = N;
	tail = 0;
}
int queue_empty()
{
	return head % N == tail;
}
void queue_put(int item)
{
	if (tail == head % N) {
		printf("error:overflow\n");
	}
	q[tail++] = item;
	tail = tail % N;
}
int queue_get()
{
	head = head % N;
	return q[head++];
}
void queue_print()
{
	int i ;
	for (i = 0;i < N;i++)
		printf("%d ",q[i]);
	printf("\n");
}
