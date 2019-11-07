typdef char elemType;
typedef int Status;
typedef struct  BiTNode
{
  elemType data;
  struct  BiTNode  *lchild;
  struct  BiTNode *rchild;
}BiTNode;  //结构体类型定义
typedef BiTNode *BiTree;///这是一个指针
typedef BiTree Selemtype_Sq;
typedef struct 
{
  BiTree left;   //指针
  BiTree right;
  int n;  //当前节点的次序
}Node;  //存储当前节点信息
void InitBiTree(BiTree *T)
{
  *T=NUll;
}
void ClearBiTree(BiTree *T)
{
	if(*T)
	{
		if((*T)->lchild)
			ClearBiTree(&(*T)->lchild);
		if((*T)->rchild)
			ClearBiTree(&(*T)->rchild);
		free(*T);
		*T=NUll;
	}
}
void DestroyBiTree(BiTree *T)
{
	//二叉树无法销毁
}
Status BiTreeEmpty(BiTree *T）
{
	return T==NUll?TRUE:error;
}
Status CreateBiTree(FILE *fp,BiTree *T)
{
	char ch;
	Scanf(fp,"%c",&ch);
	if(ch==" ")
		*T=NUll;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTree));
		if(!(*T))
			exit(overflow);

		(*T)->data=ch;
		CreateBiTree(fp,&(*T)->lchild);
		CreateBiTree(fp,&(*T)->rchild);
	}
	return 1;
}
int BiTreeLength(BiTree T)
{
	Node node[100];
	int i,len;
	i=len=0;
	if(T)
	{
		node[i].left=T->lchild;
		node[i].right=T->rchild;
		node[i].n=1;
		if(node[i].n>len)
			len=node[i].n;
		while(i>0)
		{
			while(node[i].left)
			{
				node[i+1].left=node[i].left->lchild;
				node[i+1].right=node[i].right->rchild;
				node[i+1].n=2*node[i].n;
				node[i].left=NUll;
				i++;
				if(node[i].n>len)
					len=node[i].n;
			}
			if(node[i].right)
			{
				node[i+1].left=node[i].right->lchild;
				node[i+1].right=node[i].right->rchild;
				node[i+1].n=2*node[i].n+1;
				node[i].right=NUll;
				i++;
				if(node[i].n>len)
					len=node[i].n;
			}
			if(node[i].left==NUll&&node[i].right==NUll)
				i--;
		}
	}
	return len;
}
int BiTreeDepth(BiTree T)
{
	int LD,RD;
	if(T==NUll)
		return 0;
	else
	{
		LD=BiTreeDepth(T->lchild);
		RD=BiTreeDepth(T->rchild);
		return (LD>=RD?LD:RD)+1;
	}
}
Status Root(BiTree T,elemType *e)
{
	if(!T)
		return error;
	else
	{
		*e=T->data;
		return 1;
	}
}
elemType Value(BiTree p)
{
	return p->data;
}
void Assign(BiTree p,elemType value)
{
    p->data=value;
}
elemType Parent(BiTree T,elemType e)
{
	BiTree node[100];
	int i=0;
	if(T==NUll||(T!=NUll&&e==T->data))
		return '\0';
	node[i]=T;
	while(i>=0)
	{
		while(node[i].lchild)
		{
			if(node[i].lchild->data==e)
				return node[i].data;
			node[i+1]=*(node[i].lchild)
			node[i+1].lchild=NUll;
			i++;
		}
		if(node[i].rchild)
		{
			if(node[i].rchild->data==e)
				return node[i].data;
			node[i+1]=*(node[i].rchild);
			node[i].rchild=NUll;
			i++;
		}
		if(node[i].lchild==NUll&&node[i].rchild==NUll)
			i--;
	}
	if (i<0)
		return '\0';
}
elemType LeftChild(BiTree T,elemType e)
{
	BiTree node[100];
	int i=0;
	if(!T)
		return '\0';
	node[i]=*T;
	while(i>=0)
	{
		while(node[i].data!=e&&node[i].lchild)
		{
			node[i+1]=*(node[i].lchild);
			node[i].lchild=NUll;
			i++;
		}
		if(node[i].data==e)
		{
			if(node[i].lchild)
				return node[i].lchild->data;
			else
				return '\0';
		}
		if(node[i].rchild)
		{
			node[i+1]=*(node[i].rchild);
			node[i].rchild=NUll;
			i++;
		}
		if(node[i].lchild==NUll&&node[i].rchild==NUll&&node[i].data!=e)
			i--;
	}
	if(i<0)
		return '\0';
}
elemType RightChild(BiTree T,elemType e)
{
	BiTree node[100];
	int i=0;
	if(!T)
		return '\0';
	node[i]=*T;
	while(i>=0)
	{
		while(node[i].data!=e&&node[i].lchild)
		{
			node[i+1]=*(node[i].lchild);
			node[i].lchild=NUll;
			i++;
		}
		if(node[i].data==e)
		{
			if(node[i].rchild)
				return node[i].rchild->data;
			else
				return '\0';
		}
		if(node[i].rchild)
		{
			node[i+1]=*(node[i].rchild);
			node[i].rchild=NUll;
			i++;
		}
		if(node[i].lchild==NUll&&node[i].rchild==NUll&&node[i].data!=e)
			i--;
	}
	if(i<0)
		return '\0';
}
elemType LeftSibing(BiTree T,elemType e)
{
	BiTree node[100];
	int i=0;
	if(T==NUll|(T!NUll&&e==T->data))
		return '\0';
	node[i]=*T;
	while(i>=0)
	{
		while(node[i].rchild)
		{
			if(node[i].rchild->data==e)
			{
				if(node[i].lchild)
					return node[i].lchild->data;
				else
					return '\0';
			}
			node[i+1]=*(node[i].rchild);
			node[i].rchild=NUll;
			i++;
		}
		if(node[i].lchild)
		{
			if(node[i].lchild->data==e)
				return '\0';
			node[i+1]=*(node[i].lchild);
			node[i].lchild=NUll;
			i++;
		}
		if(node[i].lchild==NUll&&node[i].rchild==NUll)
			i--;
	}
	if(i<0)
		return '\0';
}
elemType RightSibing(BiTree T,elemType e)
{
	BiTree node[100];
	int i=0;
	if(T==NUll|(T!NUll&&e==T->data))
		return '\0';
	node[i]=*T;
	while(i>=0)
	{
		while(node[i].lchild)
		{
			if(node[i].lchild->data==e)
			{
				if(node[i].rchild)
					return node[i].rchild->data;
				else
					return '\0';
			}
			node[i+1]=*(node[i].lchild);
			node[i].lchild=NUll;
			i++;
		}
		if(node[i].rchild)
		{
			if(node[i].rchild->data==e)
				return '\0';
			node[i+1]=*(node[i].rchild);
			node[i].rchild=NUll;
			i++;
		}
		if(node[i].lchild==NUll&&node[i].rchild==NUll)
			i--;
	}
	if(i<0)
		return '\0';
}
BiTree LocateBiTree_1(BiTree T,elemType e)
{
	BiTree node[100];
	int i=0;
	if(T==NUll)
		return NUll;
	if(T->data==e)
		return T;
	node[i]=*T;
	while(i>=0)
	{
		while(node[i].lchild)
		{
			if(node[i].lchild->data==e)
				return node[i].lchild;
			node[i+1]=*(node[i].lchild);
			node[i].lchild=NUll;
			i++;
		}
		if(node[i].rchild)
		{
			if(node[i].rchild->data==e)
				return node[i].rchild;
			node[i+1]=*(node[i].rchild);
			node[i].rchild=NUll;
			i++;
		}
		if(node[i].lchild==NUll&&node[i].rchild==NUll)
			i--;
	}
	if(i<0)
		return NUll;
}
BiTree LocateBiTree_2(BiTree T,elemType e)
{
	BiTree p=NUll;
	if(T)
	{
		if(T->data==e)
			p=T;
		else
		{
			if(p=LocateBiTree_2(T->lchild,e))
				return p;
			fi(p=LocateBiTree_2(T->rchild,e))
			return p;
		}
	}
	return p;
}
Status InsertBiTree(BiTree T,elemType e,BiTree T0,int LR)
{
	BiTree p=LocateBiTree_1(T,e);
	if(p)
	{
		T0->rchild=LR?p->rchild:p->lchild;
		LR?(p->rchild=T0):(p->lchild=T0);
		return 1;
	}
	return error;
}
Status DeleteBiTree(BiTree T,elemType e,int LR)
{
	BiTree p=LocateBiTree_2(T,e);
	if(p)
	{
		LR?ClearBiTree(&(p->rchild)):ClearBiTree(&(p->lchild));
		return 1;
	}
	return error;
}
void LevelOrderTraverse(BiTree T,void(visit)(elemType))
{
	int i,j;
	BiTree p[100];
	i=j=0;
	if(T)
		p[i++]=T;
	while(i<j)
	{
		visit(p[i]->data);
		if(p[i]->lchild)
			p[j++]=p[i]->lchild;
		if(p[i]->rchild)
			p[j++]=p[i]->rchild;
		i++;
	}
}
void PreOrderTraverse_1(BiTree T,void(visit)(elemTyp))
{
	if(T)
	{
		visit(T->data);
		PreOrderTraverse_1(T->lchild,visit);
		PreOrderTraverse_1(T->rchild,visit);
	}
}
Status PreOrderTraverse_2(BiTree T,Status(visit)(elemType))
{
	if(T)
	{
		if(visit(T->data))
		{
			PreOrderTraverse_2(T->lchild,visit);
			PreOrderTraverse_2(T->rchild,visit);
		}
		return 1;
	}
	else
		return error;
}
void InOrderTraverse_1(BiTree T,void(visit)(elemType))
{
	if(T)
	{
		InOrderTraverse_1(T->lchild,visit);
		visit(T->data);
		InOrderTraverse_1(T->rchild,visit);
	}
}
Status InOrderTraverse_2(BiTree T,Status(visit)(elemType))
{
	SqStack S;
	elemType p;
	InitSqstack_Sq(&S);
	Push_Sq(&S,T);
	while(!StackEmpty_Sq(S))
	{
		while(GetTop_Sq(S,&p,)&&p)
			Push_Sq(&S,p->lchild);
		Pop_Sq(&S,&p);
		if(!StackEmpty_Sq(S))
		{
			Pop_Sq(&S,&p);
			if(!visit(p->data))
				return error;
			Push_Sq(&S,p->rchild);
		}
		return 1;
	}
}
Status InOrderTraverse_3(BiTree T,Status(visit)(elemType))
{
	SqStack S;
	elemType p;
	InitSqstack_Sq(&S);
	p=T;
	while(p||!StackEmpty_Sq(S))
	{
		if(p)
		{
			Push_Sq(&S,p);
			p=p->lchild;
		}
		else
		{
			Pop_Sq(&S,&p);
			if(visit(p->data))
				return error;
			p=p->rchild;
		}
	}
	return 1;
}
void PostOrderTraverse(BiTree T,void(visit)(elemType))
{
	if(T)
	{
		PostOrderTraverse(T->lchild,visit);
		PostOrderTraverse(T->rchild,visit);
		visit(T->data);
	}
}
void PrintTree(BiTree T)
{
	int row,col;
	int i,j,m,l,r;
	BiTreea[100][100]={};
	if(T)
	{
		row=BiTreeDepth(T);
		col=pow(2,row)-1;
		for(i=1;i<=row-1;i++)
		{
			for(j=1;j<=pow(2,i-1);j++)
			{
				m=(2*j-1)*pow(2,row-1);
				l=(4*j-3)*pow(2,row-i-1);
				r=(4*j-1)*pow(2,row-i-1);
				if(i==1)
					a[i][m]=*T;
				if(a[i][m].lchild)
					a[i+1][l]=*(a[i][m].lchild);
				if(a[i][m].rchild)
					a[i+1][r]=*(a[i][m].rchild);
			}
		}
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=col;j++)
			{
				if(a[i][j].data)
					printf("%c\n",a[i][j].data);
					else
					printf(" \n");
			}
			printf("\n");
		}
	}
}
