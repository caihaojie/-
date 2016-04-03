#include <stdio.h>
#include <stdlib.h>
#define	LENGTH 11


int Data()
{
	static int data = 0;
	return ++data;
}

int Data_2()
{
	static int data = 6;
	return data--;
}

struct LNode
{
	int data;
	struct LNode *next;
};

typedef struct LNode LNode;

struct {
	LNode *top;
	LNode *base;
	int stacksize;
}Stack;

int GetLength(LNode* p)
{
	int length = 0;
	while (p->next)
	{
		p = p->next;
		length++;
	}
	return length;
}



LNode* Create(int length)
{
	int temp, temp_2 = length;
	LNode *head, *r, *n;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	n = head;
	for (temp = 0; temp < length; temp++)
	{
		r = (LNode*)malloc(sizeof(LNode));
		if (temp_2-- > 6)
			r->data = Data();
		else
			r->data = Data_2();
		r->next = NULL;
		n->next = r;
		n = r;
	}
	return head;
}



main()
{
	int temp, length = 0;
	LNode *head, *p, *stack;
	head = Create(LENGTH);
	p = head->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	length = GetLength(head);
	Stack.stacksize = length + 1;
	if (!(Stack.top = Stack.base = (LNode*)malloc(sizeof(LNode) * Stack.stacksize)))
		exit(0);
	p = head->next;
	for (temp = 0; temp < length; temp++)
	{
		Stack.top->data = p->data;
		p = p->next;
		Stack.top++;

	}

	p = head->next;

	while (Stack.top != Stack.base)
	{

		if ((Stack.top - 1)->data != p->data)
		{
			printf("NO\n");
			exit(1);
		}
		Stack.top--;
		p = p->next;
	}
	printf("YES\n");

	free(Stack.top);
	p = head->next;
	while (p)
	{
		head = p->next;
		free(p);
		p = head;
	}
}