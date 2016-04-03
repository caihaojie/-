#include <stdio.h>
#include <stdlib.h>

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

void Resort(LNode *head)
{
	LNode *left, *p, *right;
	if (!(left = head->next))
	{
		printf("EMPTY/n");
		exit(0);
	}
	if (!(p = left->next))
	{
		printf("Only one element");
		exit(1);
	}
	if (!(right = p->next))
	{
		p->next = left;
		left->next = NULL;
		head = p;
		printf("Only two element");
		exit(2);
	}
	left->next = NULL;
	while (right)
	{
		p->next = left;
		left = p;
		p = right;
		right = right->next;
	}
	p->next = left;
	head->next = p;
}

main()
{
	LNode *head_A, *head_B, *head_C,*p_A,*p_B,*temp;
	head_A = Create(6);
	head_B = Create(8);
	Resort(head_A);
	Resort(head_B);
	head_C = head_B;
	p_A = head_A;
	p_B = head_B;
	while (p_B)
	{
		if (p_B->next->data >= p_A->next->data)
		{

		}
		else if (p_B->data < p_A->data)
		{

		}
	}
}