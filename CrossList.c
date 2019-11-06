typedef int elemtype;
typedef struct OLnode
{
	int i,j;
	elemtype e;
	struct  OLnode *right;
	struct  OLnode *down;
}OLnode;
typedef OLnode *OLink;
typedef struct
{
	OLink *rhead;
	OLink *chead;
	int mu,nu,tu;
}CrossList;
int CreateSMatrix_OL(FILE *fp,int n)
{
	int count,k;
	OLnode *p,*q;
	CrossList *M;
	if(n<1)
		return ERROR;
	va_list ap;
	va_start(ap,n);
	for (count=1;count<=n;count++)
	{
		M=va_arg(ap,CrossList *);
		Scanf(fp,"%d%d%d",&((*M).mu),&((*M).nu),&((*M).tu));
		(*M).rhead=(OLink*)malloc(((*M).mu+1)*sizeof(OLink));
		if(!(*M).rhead)
			exit(overflow);
		for(k=0;k<=(*M).mu;k++)
			(*M).rhead[k]=NULL;
		for (k=0;k<=(*M).nu;k++)
			(*M).chead[k]=NULL;
		for(k=1;k<=(*M).tu;k++)
		{
			p=(OLnode*)malloc(sizeof(OLnode));
			if(!p)
				exit(overflow);
			Scanf(fp,"%d%d%d",&(p->i),&(p->j),&(p->e));
			p->right=p->down=NULL;
			if((*M).rhead[p->i]==NULL||(*M).rhead[p->i]->j>p->j)
			{
				p->right=(*M).rhead[p->i];
				(*M).rhead[p->i]=p;
			}
			else
			{
				for(q=(*M).rhead[p-i];(q->right)&&(q->right->j<p->j);q=p->right)
					;
				if(q->j=p->j||((q->right)&&(q->right->j==p->j))
				{
					printf("此位置已经被占用\n");
					exit(overflow);
				}
				p->right=q->right;
				q->right=p;
			}
			if((*M).chead[p->j]==NULL||(*M).chead[p->j]->i>p->i)
			{
				p->down=(*M).chead[p->j];
				(*M).chead[p-j]=p;
			}
			else
			{
				for(q=(*M).chead[p->j];(q->down)&&(q->down->i<p->i);q=q->down)
					;
				if(q->i==p->i||((q->down)&&q->down->i==p->i))
				{
					printf("此位置已经被占用\n");
					exit(overflow);
				}
				p->down=q->down;
				q->down=p;
			}
		}
	}
	va_end(ap);
	return 1;
}
void DestroySMtrix_OL(CrossList *M)
{
	int i;
	OLnode *p,*q;
	for(i=1;i<=(*M).mu;++i)
	{
		p=(*M).rhead;
		while(p)
		{
			q=p;
			p=p->right;
			free(q);
		}
	}
	free((*M).rhead);
	free((*M).chead);
	(*M).rhead=(*M).chead=NULL;
	(*M).mu=(*M).nu=(*M).tu=0;
}
void PrintSMtrix_OL(CrossList M)
{
	int i,j;
	OLnode *p;
	for(i=1;i<M.mu;++i)
	{
		p=M.rhead[i];
		for(j=1;j<M.nu;++j)
		{
			if(p&&p->j==j)
			{
				printf("%3d\n",p->e);
				p=p->right;
			}
			else
				printf("0\n");
		}
		printf("\n\n");
	}
}
