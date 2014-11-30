#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *next;
}KeyNode;

void bucket_sort(int keys[],int size,int bucket_size) {
	int i,j;
	KeyNode **bucket_table = (KeyNode **)malloc(bucket_size * sizeof(KeyNode*));
	for(i = 0;i < bucket_size;i++) {
		bucket_table[i] = (KeyNode*)malloc(sizeof(KeyNode));
		bucket_table[i]->key = 0;
		bucket_table[i]->next = NULL;
	}
	for(j = 0;j < size;j++) {
		KeyNode *node = (KeyNode *)malloc(sizeof(KeyNode));
		node->key = keys[j];
		node->next = NULL;
		int index = keys[j]/10;
		KeyNode *p = bucket_table[index];
		if(p->key == 0) {
			bucket_table[index]->next = node;
			(bucket_table[index]->key)++;
		}else {
			while(p->next != NULL && p->next->key <= node->key)
				p = p->next;
			node->next = p->next;
			p->next = node;
			(bucket_table[index]->key)++;
		}
	}
	//print result
	KeyNode * k = NULL;
	for(i = 0;i < bucket_size;i++)
		for(k = bucket_table[i]->next;k!=NULL;k=k->next)
			printf("%d ",k->key);
	printf("\n");
}


int main()
{
	int raw[] = {49,38,65,97,76,13,27,49};
	int size = sizeof(raw)/sizeof(int);
	bucket_sort(raw,size,10);
}
