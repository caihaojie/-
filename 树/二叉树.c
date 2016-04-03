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
非递归方法中序遍历二叉树
参数 二叉树结点指针
*/
void midorder(bitree t);

int DLR(node *root);

int LDR(node *root);

/*
非递归方法后序遍历二叉树
参数 二叉树结点指针
*/
void postorder_l(bitree t);

int LRD(node *root);

/*
将二叉树对称交换，即求二叉树镜像
参数 二叉树结点指针
*/
int LRexchange(node *root);

/*
求二叉树的高度，即深度
参数 二叉树结点指针
*/
int HeightofTree(node *root);

/*
获取Layer层的结点个数
参数 二叉树结点指针,层数（计1为第一层）
当层数Layer = -1 时，令sum = 0
返回值 第Layer层结点个数
*/
int getLayerWidth(node *root, int Layer);

/*
求二叉树的宽度，即求最大结点数的层所具有的结点数
参数 二叉树结点指针,二叉树深度（计1为第一层）
返回值 二叉树的宽度
需要调用getLayerWidth()
*/
int getWidthMax(node *root, int length);

/*
从Layer层开始，从左往右顺序输出
参数 二叉树结点指针,要输出的层数（计1为第一层）
*/
int showLayer(node *root, int Layer);

/*
分层遍历二叉树，即按层次从上往下，从左往右顺序访问
参数 二叉树结点指针,二叉树深度
需要调用showLayer()
*/
int ShowbyLayer(node *root, int height);

/*
二叉树中的结点个数
参数 二叉树结点指针
返回值 结点总数
*/
int NodeSum(node *root);

/*
求二叉树中叶子结点的个数
参数 二叉树结点指针
返回值 叶子结点的个数
*/
int LeafNodeSum(node *root);

/*
判断两棵二叉树是否结构相同
参数 第一个二叉树结点指针，第二个二叉树结点指针
返回值 1->结构相同 0->结构不同
*/
int BitreeIsSame(node *first, node*second);

/*
已知前序序列和中序序列，构造二叉树
参数 前序序列,中序序列
返回值 二叉树根结点指针
*/
bitree BuildTreeByProAndMid(char *pro, char *mid);

int main()
{
	/*
	bitree t;
	t = buildtree();//  测试用例：abc00d00e0fg000
	printf("非递归前序遍历：\n");
	preorder(t);
	printf("递归前序遍历：\n");
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
	s.top = -1;//置栈空
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
非递归方法中序遍历二叉树
参数 二叉树结点指针
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
	if (root != NULL) //非空二叉树
	{
		printf("%c", root->data); //访问D
		DLR(root->lchild); //递归遍历左子树
		DLR(root->rchild); //递归遍历右子树
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
这是非递归后序实现
*/
void postorder_l(bitree t)
{
	bitree lastvist = NULL;
	seqstack s;
	s.top = -1;//置栈空
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
将二叉树对称交换，即求二叉树镜像
参数 二叉树结点指针
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
求二叉树的高度，即深度
参数 二叉树结点指针
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
已知前序序列和中序序列，构造二叉树
参数 二叉树结点指针
*/
int reBuildTree(node *root)
{

	return 0;
}

/*
从Layer层开始，从左往右顺序输出
参数 二叉树结点指针,要输出的层数（计1为第一层）
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
获取Layer层的结点个数
参数 二叉树结点指针,层数（计1为第一层）
当层数Layer = -1 时，令sum = 0
返回值 第Layer层结点个数
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
分层遍历二叉树，即按层次从上往下，从左往右顺序访问
参数 二叉树结点指针,二叉树深度
*/
int ShowbyLayer(node *root, int height)
{
	int temp;
	for (temp = 1; temp <= height; temp++)
	{
		printf("\n第%d层\n", temp);
		showLayer(root, temp);
	}
	printf("\n");
	return 1;
}

/*
求二叉树的宽度，即求最大结点数的层所具有的结点数
参数 二叉树结点指针,二叉树深度（计1为第一层）
返回值 二叉树的宽度
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
二叉树中的结点个数
参数 二叉树结点指针
返回值 结点总数
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
求二叉树中叶子结点的个数
参数 二叉树结点指针
返回值 叶子结点的个数
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
判断两棵二叉树是否结构相同
参数 第一个二叉树结点指针，第二个二叉树结点指针
返回值 1->结构相同 0->结构不同
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
已知前序序列和中序序列，构造二叉树
参数 前序序列,中序序列
返回值 二叉树根结点指针
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