#include <stdlib.h>

typedef struct stacknode* link;
struct stacknode {
	int item;
	link next;
};
static link head;

link NEW(int item,link next)
{
	link x = malloc(sizeof *x);
	x->item = item;
	x->next = next;
	return x;
}
void stack_init(int maxN)
{
	head = NULL;
}
int stack_empty()
{
	return head == NULL;
}
void stack_push(int item)
{
	head = NEW(item,head);
}
int stack_pop()
{
	int item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}
