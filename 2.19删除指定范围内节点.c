#include <stdio.h>
#include <stdlib.h>
#define	MINK 5
#define MAXK 8
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
	if (MAXK <= MINK)
	{
		printf("Error : maxk > mink\n");
		exit(1);
	}
	LNode *head, *p, *left, *right, *temp;
	head = Create(10);
	if (!(p = head->next))
	{
		printf("Empty line");
		exit(1);
	}
	left = right = NULL;

	while (p)
	{
		if (p->data >= MAXK)
			break;
		else if (p->data < MAXK)
			right = p;
		p = p->next;
	}

	left = head->next;
	while (left)
	{
		if (left->data <= MINK)
		{
			p = left;
			left = left->next;
		}
		else if (left->data > MINK)
			break;

	}
	if (right)
		p->next = right->next;
	if (left)
	{
		while (left != right)
		{
			temp = left->next;
			free(left);
			left = temp;

		}
	}



	head = head->next;
	while (head)
	{
		temp = head->next;
		printf("%d\n", head->data);
		free(head);
		head = temp;
	}
}