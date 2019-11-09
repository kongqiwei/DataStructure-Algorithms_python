#define MAX_TRUE_SIZE 100
typedef char ElemType;
typedef struct  CTnode
{
	int child;
	struct CTnode *next;
}CTnode;

typedef CTnode *ChildPtr;
typedef struct
{
	int parent;
	ElemType data;
	ChildPtr firstchild;
}CTbox;
typedef struct 
{
	CTbox nodes[MAX_TRUE_SIZE];
	int r;
	int n;
}CTree;
void InitTree_C(FILE *fp,CTree *T)
{
	int i;
	char tmp;
	Scanf(fp,"%d",&i);
	printf("录入根节点的位置%的\n",i); 
	Scanf(fp,"%c",&tmp);
	if(i<0||i>MAX_TRUE_SIZE-1)
	{
		printf("i值错误\n");
		exit(error);
	}
	(*T).r=i;
	(*T).n=0;
}
void FreeChild_C(ChildPtr *p)
{
	ChildPtr q;
	while(*p)
	{
		q=(*p)->next;
		free(*p);
		*p=*q;
	}
}
void ClearTree_C(CTree *T)
{
	int i;
	if((*T).n)
	{
		for(i=0;i<T->n-1;i++)
		{
			if(T->nodes[i].firstchild)
				FreeChild_C(&(T->nodes[i].firstchild));
		}
		if(T->r<=T->n-1)
		{
			if(T->nodes[i].firstchild)
				FreeChild_C(&(T->nodes[i].firstchild));
		}
		else
		{
			if(T->nodes[T->r].firstchild)
				FreeChild_C(&(T->nodes[T->r].firstchild));
		}
		(*T).n=0;
	}
}
int CreateTree(FILE *fp,CTree *T)
{
	ElemType ch,tmp;
	int i,j,k;
	ChildPtr p,q;
	Scanf(fp,"%c",&ch);
	printf("录入根节点的位置\n"，ch);
	Scanf(fp,"%c",ch);
	if(ch!=" ")
	{
		i=(*T).r;
		(*T).nodes[i].parent=-1;
		
	}
}
