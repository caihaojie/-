#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 10
typedef struct node {
	char data;
	struct node *lchild, *rchild;
} node;
typedef node *bitree;
typedef struct {
	bitree a[maxsize];
	int top;
}seqstack;

bitree buildtree();

void preorder(bitree t);

/*
�ǵݹ鷽���������������
���� ���������ָ��
*/
void midorder(bitree t);

int DLR(node *root);

int LDR(node *root);

/*
�ǵݹ鷽���������������
���� ���������ָ��
*/
void postorder_l(bitree t);

int LRD(node *root);

/*
���������Գƽ������������������
���� ���������ָ��
*/
int LRexchange(node *root);

/*
��������ĸ߶ȣ������
���� ���������ָ��
*/
int HeightofTree(node *root);

/*
��ȡLayer��Ľ�����
���� ���������ָ��,��������1Ϊ��һ�㣩
������Layer = -1 ʱ����sum = 0
����ֵ ��Layer�������
*/
int getLayerWidth(node *root, int Layer);

/*
��������Ŀ�ȣ�������������Ĳ������еĽ����
���� ���������ָ��,��������ȣ���1Ϊ��һ�㣩
����ֵ �������Ŀ��
��Ҫ����getLayerWidth()
*/
int getWidthMax(node *root, int length);

/*
��Layer�㿪ʼ����������˳�����
���� ���������ָ��,Ҫ����Ĳ�������1Ϊ��һ�㣩
*/
int showLayer(node *root, int Layer);

/*
�ֲ������������������δ������£���������˳�����
���� ���������ָ��,���������
��Ҫ����showLayer()
*/
int ShowbyLayer(node *root, int height);

/*
�������еĽ�����
���� ���������ָ��
����ֵ �������
*/
int NodeSum(node *root);

/*
���������Ҷ�ӽ��ĸ���
���� ���������ָ��
����ֵ Ҷ�ӽ��ĸ���
*/
int LeafNodeSum(node *root);

/*
�ж����ö������Ƿ�ṹ��ͬ
���� ��һ�����������ָ�룬�ڶ������������ָ��
����ֵ 1->�ṹ��ͬ 0->�ṹ��ͬ
*/
int BitreeIsSame(node *first, node*second);

/*
��֪ǰ�����к��������У����������
���� ǰ������,��������
����ֵ �����������ָ��
*/
bitree BuildTreeByProAndMid(char *pro, char *mid);

int main()
{
	/*
	bitree t;
	t = buildtree();//  ����������abc00d00e0fg000
	printf("�ǵݹ�ǰ�������\n");
	preorder(t);
	printf("�ݹ�ǰ�������\n");
	DLR(t);
	printf("\n");
	LDR(t);
	printf("\n");
	LRD(t);
	printf("\n");
	midorder(t);
	*/
	//bitree t;
	//t = buildtree();
	//printf("\nOLD:\n");
	//DLR(t);
	//LRexchange(t);
	//printf("\nNEW:\n");
	//DLR(t);
	//	int l = HeightofTree(t);
	//	printf("\n%d\n",l);
	//midorder(t);
	//ShowbyLayer(t, 4);
	//printf("\n%d\n", getWidthMax(t, 4));
	//printf("\n%d\n",NodeSum(t));
	//printf("\n");
	//printf("%d",LeafNodeSum(t));
	//postorder_l(t);
	//printf("\n%d\n", BitreeIsSame(t, t->lchild));
	//DLR(BuildTreeByProAndMid("abcdefg", "cbdaegf"));
	char *a = "abcdefg";
	char *b = "cbdaegf";
	char *c;
	char *d;
	c = strtok_s(b,a,&d);
	if (d)
		printf("233\n");
	//printf("\n%d\n%d\n",(c),(d));
	printf("\n%s\n%s\n",c,d);
	return 0;
}

bitree buildtree()
{
	char c;
	node *p;
	c = getchar();
	if (c == '0')
	{
		p = NULL;
	}
	else
	{
		p = (bitree)malloc(sizeof(node));
		p->data = c;
		p->lchild = buildtree();
		p->rchild = buildtree();
	}
	return(p);
}
void preorder(bitree t)
{
	seqstack s;
	s.top = -1;//��ջ��
	while ((t) || (s.top != -1))
	{
		while (t)
		{
			printf("%c", t->data);
			s.top++;
			s.a[s.top] = t;
			t = t->lchild;
		}//endwhile
		if (s.top>-1) {
			t = s.a[s.top];
			s.top--;
			t = t->rchild;
		}//endif
	}//endwhile
}

/*
�ǵݹ鷽���������������
���� ���������ָ��
*/
void midorder(bitree t)
{
	seqstack s;
	s.top = -1;
	while ((t) || (s.top != -1))
	{
		while (t)
		{
			s.top++;
			s.a[s.top] = t;
			t = t->lchild;
		}
		if (s.top > -1)
		{
			t = s.a[s.top];
			printf("%c", t->data);
			s.top--;
			t = t->rchild;
		}
	}
}

int DLR(node *root)
{
	if (root != NULL) //�ǿն�����
	{
		printf("%c", root->data); //����D
		DLR(root->lchild); //�ݹ����������
		DLR(root->rchild); //�ݹ����������
	}
	return(0);
}
int LDR(node *root)
{
	if (root != NULL)
	{
		LDR(root->lchild);
		printf("%c", root->data);
		LDR(root->rchild);
	}
	return(0);
}

/*
���Ƿǵݹ����ʵ��
*/
void postorder_l(bitree t)
{
	bitree lastvist = NULL;
	seqstack s;
	s.top = -1;//��ջ��
	while ((t) || (s.top != -1))
	{
		while (t)
		{
			s.top++;
			s.a[s.top] = t;
			t = t->lchild;
		}
		t = s.a[s.top];
		if (t->rchild == NULL || t->rchild == lastvist)
		{
			putchar(t->data);
			lastvist = s.a[s.top];
			s.top--;
		}
		else
			t = t->rchild;
	}
}

int LRD(node *root)
{
	if (root != NULL)
	{
		LRD(root->lchild);
		LRD(root->rchild);
		printf("%c", root->data);
	}
	return(0);
}

/*
���������Գƽ������������������
���� ���������ָ��
*/
int LRexchange(node *root)
{
	node *temp;
	if (root != NULL)
	{
		temp = root->lchild;
		root->lchild = root->rchild;
		root->rchild = temp;

		LRexchange(root->lchild);
		LRexchange(root->rchild);
	}

	return 0;
}
/*
��������ĸ߶ȣ������
���� ���������ָ��
*/
int HeightofTree(node *root)
{
	static int height = 0;
	static int heightMax = 0;
	if (root)
	{
		height++;
		HeightofTree(root->lchild);
		HeightofTree(root->rchild);
		if (height > heightMax)
			heightMax = height;
		height--;
	}
	return heightMax;
}

/*
��֪ǰ�����к��������У����������
���� ���������ָ��
*/
int reBuildTree(node *root)
{

	return 0;
}

/*
��Layer�㿪ʼ����������˳�����
���� ���������ָ��,Ҫ����Ĳ�������1Ϊ��һ�㣩
*/
int showLayer(node *root, int Layer)
{
	static int temp = 0;
	if (root)
	{
		temp++;
		showLayer(root->lchild, Layer);
		showLayer(root->rchild, Layer);

		temp--;
		if (temp == (Layer - 1))
		{
			printf("%c", root->data);
			return 0;
		}
	}
	return 1;
}

/*
��ȡLayer��Ľ�����
���� ���������ָ��,��������1Ϊ��һ�㣩
������Layer = -1 ʱ����sum = 0
����ֵ ��Layer�������
*/
int getLayerWidth(node *root, int Layer)
{
	static int temp = 0;
	static int sum = 0;
	if (Layer == -1)
		sum = 0;
	if (root)
	{
		temp++;
		getLayerWidth(root->lchild, Layer);
		getLayerWidth(root->rchild, Layer);

		temp--;
		if (temp == (Layer - 1))
		{
			sum++;
			return 1;
		}
	}
	return sum;
}

/*
�ֲ������������������δ������£���������˳�����
���� ���������ָ��,���������
*/
int ShowbyLayer(node *root, int height)
{
	int temp;
	for (temp = 1; temp <= height; temp++)
	{
		printf("\n��%d��\n", temp);
		showLayer(root, temp);
	}
	printf("\n");
	return 1;
}

/*
��������Ŀ�ȣ�������������Ĳ������еĽ����
���� ���������ָ��,��������ȣ���1Ϊ��һ�㣩
����ֵ �������Ŀ��
*/
int getWidthMax(node *root, int length)
{
	int temp, temp_2, width = 0;
	for (temp = 1; temp <= length; temp++)
	{
		getLayerWidth(root, -1);
		if ((temp_2 = getLayerWidth(root, temp)) > width)
			width = temp_2;
	}
	return width;
}

/*
�������еĽ�����
���� ���������ָ��
����ֵ �������
*/
int NodeSum(node *root)
{
	static int sum = 0;
	if (root)
	{
		NodeSum(root->lchild);
		NodeSum(root->rchild);
		sum++;
	}
	return sum;
}

/*
���������Ҷ�ӽ��ĸ���
���� ���������ָ��
����ֵ Ҷ�ӽ��ĸ���
*/
int LeafNodeSum(node *root)
{
	static int leafNodeSum = 0;
	if (root)
	{
		LeafNodeSum(root->lchild);
		LeafNodeSum(root->rchild);

		if (!(root->lchild || root->rchild))
			leafNodeSum++;
	}
	return leafNodeSum;
}

/*
�ж����ö������Ƿ�ṹ��ͬ
���� ��һ�����������ָ�룬�ڶ������������ָ��
����ֵ 1->�ṹ��ͬ 0->�ṹ��ͬ
*/
int BitreeIsSame(node *first, node*second)
{
	static int result = 1;
	if ((first && !second) || (!first && second))
	{
		result = 0;
	}
	else if (first && second)
	{
		BitreeIsSame(first->lchild, second->lchild);
		BitreeIsSame(first->rchild, second->rchild);
	}
	return result;
}

/*
��֪ǰ�����к��������У����������
���� ǰ������,��������
����ֵ �����������ָ��
*/
bitree BuildTreeByProAndMid(char *pro, char *mid)
{
	char *proFirst, *proSecond, *midFirst, *midSecond;
	int lengthofFirst, lengthofSecond, temp;
	char c = *pro;
	node *p;
	if (c == '\0')
	{
		p = NULL;
	}
	else
	{
		p = (bitree)malloc(sizeof(node));
		p->data = c;
		midFirst = strtok_s(mid, pro, &midSecond);
		lengthofFirst = strlen(midFirst);
		lengthofSecond = strlen(midSecond);
		proFirst = (char*)malloc((lengthofFirst + 1) * sizeof(char));
		proSecond = (char*)malloc((lengthofSecond + 1) * sizeof(char));
		pro++;
		for (temp = 0; temp < lengthofFirst; temp++)
			*(proFirst + temp) = *(pro + temp);
		if (temp == 0)
			*proFirst = '\0';
		else
			*(proFirst + temp + 1) = '\0';
		pro += lengthofFirst;
		for (temp = 0; temp < lengthofSecond; temp++)
			*(proSecond + temp) = *(pro + temp);
		if (temp == 0)
			*proSecond = '\0';
		else
			*(proSecond + temp + 1) = '\0';

		p->lchild = BuildTreeByProAndMid(proFirst, midFirst);
		p->rchild = BuildTreeByProAndMid(proSecond, midSecond);
	}
	return p;
}