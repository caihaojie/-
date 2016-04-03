#include <stdio.h>
#include <stdlib.h>
#define SUM 10
#define KILL_NUM 5

char Data()
{
	static char data = 'a';
	return data++;
}

struct LNode
{
	char name;
	struct LNode *next;
	int status;
};

typedef struct LNode LNode;

LNode* Create(int length, LNode **last)
{
	int temp;
	LNode *head, *r, *n;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	n = head;
	for (temp = 0; temp < length; temp++)
	{
		r = (LNode*)malloc(sizeof(LNode));
		r->name = Data();
		r->status = 1;
		r->next = NULL;
		n->next = r;
		n = r;
	}
	*last = n;
	n->next = head->next;
	return head;
}


main()
{
	int temp = 1;
	LNode *left, *head = Create(SUM, &left), *p, *right;

	p = head->next;

	while (p != p->next)
	{
		if (p->status && temp == KILL_NUM)
		{
			printf("%c\n", p->name);
			p->status = 0;
			temp = 1;
			right = p->next;
			left->next = right;
			//free(p);
			p = right;
		}
		else 
		{
			temp++;
			left = p;
			p = p->next;
		}
	}

	printf("The lucky guy:\n");
	printf("%c\n", p->name);

}