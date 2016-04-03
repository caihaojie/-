#include <stdio.h>

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