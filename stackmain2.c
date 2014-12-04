#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAXSIZE 100

int main()
{
	int i,n;
	scanf("%d",&n);
	stack_init(MAXSIZE);
	while (n) {
		stack_push(n % 8);
		n = n / 8;
	}
	while (!stack_empty()) {
		i = stack_pop();
		printf("%d",i);
	}
	printf("\n");
}
