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

main()
{
	LNode *p_1, *p_2, *head;
	p_1 = p_2 = Create(1);
	head = p_1->next;

	while (p_2 && p_2->next)
	{
		p_1 = p_1->next;
		p_2 = p_2->next->next;
	}
	if (!p_2)
	{
		printf("odd\n");
		printf("%d\n", p_1->data);
		printf("%p\n", p_1);
	}
	else if (!(p_2->next))
	{
		printf("double\n");
		printf("%d\n", p_1->data);
		printf("%p\n", p_1);
		printf("%d\n", p_1->next->data);
		printf("%p\n", p_1->next);
	}

	while (head)
	{
		p_1 = head->next;
		free(head);
		head = p_1;
	}
}