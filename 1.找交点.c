#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH_1 5
#define LENGTH_2 5

int Data()
{
	srand((int)time(0));
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
	int temp;
	LNode *head, *r, *n;
	head = (LNode*)malloc(sizeof(LNode));
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

int GetLength(LNode* p, LNode** p_to_end)
{
	int length = 0;
	while (p->next)
	{
		p = p->next;
		length++;
	}
	*p_to_end = p;
	return length;
}

int GetNodeLocation(LNode *longer, LNode *shorter, LNode** p)
{
	int n = 0;
	while ((longer != shorter))
	{
		longer = longer->next;
		shorter = shorter->next;
		n++;
	}

	*p = longer;
	return n;
}


main()
{
	int n_1 = 0, n_2 = 0, n_3, n_4 = 0, temp_1;
	LNode *p_1 = NULL, *p_2 = NULL;

	LNode *p, *temp_A = NULL, *temp_B = NULL;
	LNode *n = NULL;

	LNode *head_1 = Create(LENGTH_1);
	p = head_1;

	LNode *head_2 = Create(LENGTH_2);
	p = head_2;

	head_2->next = head_1->next->next;

	n_1 = GetLength(head_1, &p_1);

	n_2 = GetLength(head_2, &p_2);


	if (p_1 != p_2)
		printf("根本不相交");
	else {
		printf("相交且");
		if (n_1 > n_2)
		{
			n_3 = n_1 - n_2;
			temp_A = head_1;
			for (temp_1 = 0; temp_1 < n_3; temp_1++)
				temp_A = head_1->next;

			n_4 = GetNodeLocation(temp_A, head_2, &n);

			printf(" 相交节点在较短链表的第 %d个节点", n_4);

		}
		else {
			n_3 = n_2 - n_1;
			temp_B = head_2;
			for (temp_1 = 0; temp_1 < n_3; temp_1++)
				temp_B = head_2->next;
			n_4 = GetNodeLocation(temp_B, head_1, &n);
			printf("相交节点在较短链表的第 %d个节点", n_4);

		}
	}
	
	while (head_1)
	{
		p = head_1->next;
		free(head_1);
		head_1 = p;
	}

	while (head_2 != n)
	{
		p = head_2->next;
		free(head_2);
		head_2 = p;
	}

}