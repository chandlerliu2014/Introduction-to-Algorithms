#include <stdlib.h>
#include "stack.h"
static int *s;
static int N;

void stack_init(int maxN)
{
	s = malloc(maxN * sizeof(int));
	N = 0;
}
int stack_empty(void) 
{
	return N == 0;
}
void stack_push(int item)
{
	s[N++] = item;
}
int stack_pop(void)
{
	return s[--N];
}
