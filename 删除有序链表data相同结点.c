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
	int temp, data;
	LNode *head, *r, *n;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	n = head;
	for (temp = 0; temp < length; temp++)
	{
		data = Data();
		r = (LNode*)malloc(sizeof(LNode));
		if (data == 6 || data == 7)
			data = 5;
		r->data = data;
		r->next = NULL;
		n->next = r;
		n = r;
	}
	return head;
}


main()
{
	LNode *head, *p, *temp;
	p = head = Create(10);
//下面只是展示创建的链表
	p = p->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}

	if (!(p = head->next))
	{
		printf("Empty");
		exit(1);
	}
//下面是实际的消除重复节点
	while (p->next)
	{
		while (p->next && p->data == p->next->data)
		{
			temp = p->next->next;
			free(p->next);
			p->next = temp;
		}

		p = p->next;

	}

	printf("\n\n\n");
	p = head->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}

	p = head;

	while (p)
	{
		temp = p->next;
		free(p);
		p = temp;
	}

}