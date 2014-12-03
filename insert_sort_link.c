#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
struct node {
	int item;
	link next;
};

int main(int argc,char *argv[])
{
	int i,N = atoi(argv[1]);
	struct node heada,headb;
	link t,x,a,b,u;
	t = &heada;
	a = t;
	for (i = 0;i < N;i++) {
		t->next = malloc(sizeof *t);
		t->next->item = rand() % 100;
		t = t->next;
		t->next = NULL;
	}
	for (t = a;t->next != NULL;t = t->next)
		printf("%d  ",t->next->item);
	printf("\n");
		
	for (b = &headb,b->next = NULL,t = a->next;t != NULL;t = u) {
		u = t->next;
		for (x = b;x->next != NULL;x = x->next)
			if(t->item < x->next->item)
				break;
		//x->next = t;
		//x->next->next = NULL;
		t->next = x->next;
		x->next = t;
	}
	for (t = b;t->next != NULL;t = t->next)
		printf("%d  ",t->next->item);
	printf("\n");
}
