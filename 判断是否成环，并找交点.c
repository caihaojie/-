#include <stdio.h>
#include <stdlib.h>
#define LENGTH 12
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
	LNode *p, *head, *first, *second, *same;
	int l_1 = 0, l_2 = 0, l;
	head = Create(LENGTH);
	p = head;
	while (p->next)
		p = p->next;

	p->next = head->next->next->next->next->next;
		first = second = head;
	do {
		first = first->next;
		if (!(second = second->next->next))
		{
			printf("ÎÞ½»µã");
			exit(1);
		}
		l_1++;
	} while (second != first);
	same = first;
	do {
		first = first->next;
		second = second->next->next;
		l_2++;
	} while (second != first);

	p = head;
	if ((l = l_1 - l_2) > 0)
	{
		while (l)
		{
			l--;
			p = p->next;
		}
	}
	else if (l < 0)
	{
		l = -l;
		while (l)
		{
			l--;
			same = same->next;
		}
	}
	while (p != same)
	{
		p = p->next;
		same = same->next;
	}
	printf("%d\n%p", p->data, p);

}




