#include <stdio.h>
#include <stdlib.h>
#define LENGTH 4
#define K 2

int Data()
{
	static int data = 0;
	return ++data;
}

struct LNode
{
	int data;
	struct LNode *next;
};

typedef struct LNode LNode;

LNode* Create(int length)
{
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

main()
{
	LNode *head, *first, *second;
	int temp = 0;
	first = second = head = Create(LENGTH);
	for (temp = 0; temp < K; temp++)
	{
		first = first->next;
		if (!first)
		{
			printf("NOT EXIT");
			exit(0);
		}
	}

	while (first)
	{
		first = first->next;
		second = second->next;
	}
	printf("%p\n%d\n", second,second->data);

	while (head)
	{
		first = head->next;
		free(head);
		head = first;
	}
}