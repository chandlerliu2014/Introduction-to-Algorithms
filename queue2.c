
#include <stdlib.h>

typedef struct queuenode* link;
struct queuenode {
	int item;
	link next;
};
static link head,tail;

link NEW(int item,link next)
{
	link x = malloc(sizeof *x);
	x->item = item;
	x->next = next;
	return x;
}
void queue_init(int maxN)
{
	head = NULL;
}
int queue_empty()
{
	return head == NULL;
}
void queue_put(int item)
{
	if (head == NULL) {
		head = (tail = NEW(item,head));
		return;
	}
	tail->next = NEW(item,tail->next);
	tail = tail->next;
}
int queue_get()
{
	int item = head->item;
	link t = head->next;
	free(head);
	head = t;
	return item;
}
