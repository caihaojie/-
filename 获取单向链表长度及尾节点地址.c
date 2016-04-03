#include <stdio.h>

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