#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Data()
{
	return (rand() % 10);
}

struct LNode
{
	int data;
	struct LNode *next;
};

typedef struct LNode LNode;

LNode* Create(int length)
{
	srand((int)time(0));
	int temp;
	LNode *head, *r, *n;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	n = head;
	for (temp = 0; temp < length; temp++)
	{
		r = (LNode*)malloc(sizeof(LNode));
		r->data = Data();
		r->next = NULL;
		n->next = r;
		n = r;
	}
	return head;
}
