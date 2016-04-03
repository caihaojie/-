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
		exit(1);
	}
	if (!(p = left->next))
	{
		exit(1);
		printf("Only one element");

	}
	if (!(right = p->next))
	{
		p->next = left;
		left->next = NULL;
		head = p;
		printf("Only two element");
		exit(1);
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
	LNode *A, *B1, *B2, *head, *p;
	int i = 8;
	A = Create(5);
	Resort(A);
	head = B1 = Create(7);
	Resort(head);

	p = head->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n\n");
	p = A->next;
	while (p)
	{
		p->data = i--;
		printf("%d\n", p->data);
		p = p->next;
	}

	printf("\n\n");

	if (!(B2 = B1->next))
	{
		printf("B is empty");
		exit(0);
	}
	if (!(A = A->next))
	{
		printf("A is empty");
		exit(1);
	}
	while (A->next&&B2->next)
	{
		if (A->data >= B2->data)
		{
			B1->next = A;
			A = A->next;
			B1 = B1->next;
			B1->next = B2;
		}
		else if (A->data < B2->data)
		{
			B1 = B2;
			B2 = B2->next;
			continue;
		}
	}

	if (!B2->next)
	{
		B2->next = A;
	}

	p = head->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}


	//free
	p = head;
	while (head)
	{
		p = head->next;
		free(head);
		head = p;
	}

}