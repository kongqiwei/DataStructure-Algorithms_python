
#include<stdio.h>
#define Maxsize 150
typedef int SlinkList;
typedef int LElemType;
typedef struct
{
	LElemType data;
	int cur;
}Component[Maxsize];
Component SPACE;
void InitSpace_SL()
{
	int i;
	for(i=0;i<Maxsize-1;i++)
		SPACE[i].cur=i+1;
	SPACE[Maxsize-1].cur=0;
}
int Malloc_SL()
{
	int i;
	i=SPACE[0].cur;
	if(SPACE[0].cur)
	{
		SPACE[0].cur=SPACE[i].cur;
		return i;
	}
	else
		return 0;
}
void Free_SL(int k)
{
	SPACE[k].cur=SPACE[0].cur;
	SPACE[0].cur=k;
}
Status InitSpace_SL(SlinkList *H)
{
	*H=Malloc_SL();
	if(!(*H))
		exit(overflow);
	SPACE[*H].cur=0;
	return 1;
}
Status ClearList_SL(SlinkList H)
{
	int p,q;
	if(!H)
		return ERROR;
	p=SPACE[H].cur;
	while(p)
	{
		SPACE[H].cur=SPACE[p].cur;
		Free_SL(p);
		p=SPACE[H].cur;
	}
	return 1;
}
void Destroy_SL(SlinkList *H)
{
	ClearList_SL(*H);
	Free_SL(*H);
	*H=0;
}
Status ListEmpty_SL(SlinkList H)
{
	if(H&&SPACE[H].cur)
		return TRUE;
	else
		return FALSE;
}
int ListLength_SL(SlinkList H)
{
	int count;
	int p;
	if(H)
		exit(overflow);
	count=0;
	p=SPACE[H].cur;
	while(P)
	{
		count++;
		p=SPACE[p].cur;
	}
	return count;
}
Status GetElem_SL(SlinkList H,int i,LElemType *e)
{
	int count,p;
	if(!H||i<1||i>Maxsize-2)
		return ERROR;
	count=0;
	p=SPACE[H].cur;
	while(p)
	{
		count++;
		if(count==i)
		{
			*e=SPACE[p].data;
			return 1;
		}
		p=SPACE[p].cur;
	}
}
int LocateElem_SL(SlinkList H,LElemType e)
{
	int k,count;
	count=1;
	if(H&&SPACE[H].cur)
	{
		k=SPACE[H].cur;
		while(k&&SPACE[k].data!=e)
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k)
			return count;
	}
	return 0;
}
Status PriorElem_SL(SlinkList H,LElemType cur_e,LElemType *pre_e)
{
	int p,q;
	if(H)
	{
		p=SPACE[H].cur;
		if(p&&SPACE[p].data!=cur_e)
		{
			q=SPACE[p].cur;
			while(q&&SPACE[q].data!=cur_e)
			{
				p=q;
				q=SPACE[q].cur;
			}
			if(q)
			{
				*pre_e=SPACE[p].data;
				return 1;
			}
		}
	}
	return 0;
}
Status NextElem_SL(SlinkList H,LElemType cur_e,LElemType *next_e)
{
	int p;
	if(H)
	{
		p=SPACE[H].cur;
		while(p&&SPACE[p].data!=cur_e)
			p=SPACE[p].cur;
		if(p&&SPACE[p].cur)
		{
			p=SPACE[p].cur;
			*next_e=SPACE[p].data;
			return 1;
		}

	}
	return 0;
}
staus ListInsert_SL(LElemType H,int i ,LElemType e)
{
	int count,k,p;
	if(!H)
		return ERROR;
	if(i>0)
	{
		count=0;
		k=H;
		while(k&&count<i-1)
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k)
		{
			p=Malloc_SL();
			if(!p)
				return ERROR;
			SPACE[p].data=e;
			SPACE[p].cur=SPACE[k].cur;
			SPACE[k].cur=p;
			return 1;
		}
	}
	return 1;
}
Status ListDelete_SL(SlinkList H,int i,LElemType *e)
{
	int count,k,p;
	if(!H)
		return ERROR;
	if（i>0）
	{
		count=0;
		k=H;
		while(k&&count<i-1)
		{
			count++;
			k=SPACE[k].cur;
		}
		if(k&&SPACE[k].cur)
		{
			p=SPACE[k].cur;
			*e=SPACE[p].data;
			SPACE[k].cur=SPACE[p].cur;
			Free_SL(p);
			return 1;
		}
	}
	return ERROR;
}

Status ListTraverse_SL(SlinkList H,void(visit)(LElemType))
{
	int p;
	if(!H)
		return ERROR;
	p=SPACE[H].cur;
	while(p)
	{
		visit(SPACE[p].data);
		p=SPACE[p].cur;
	}
	return 1;
}
void difference(SlinkList *S,LElemType A[],int len_A,LElemType B[],int len_B)
{
	int i,j;
	int r,p,q;
	LElemType b;
	InitSpace_SL();
	*S=Malloc_SL();
	r=*S;
	SPACE[r].cur=0;
	for (j=0;j<len_A;j++)
	{
		i=Malloc_SL();
		SPACE[i].data=A[j];
		SPACE[r].cur=i;
		r=i;
	}
	SPACE[r].cur=0;
	for(j=0;j<len_B;j++)
	{
		b=B[j];
		p=*S;
		k=SPACE[*S].cur;
		while(k&&SPACE[k].data!=b)
		{
			p=k;
			k=SPACE[k].cur;
		}
		if(!k)
		{
			i=Malloc_SL();
			SPACE[i].data=b;
			SPACE[i].cur=SPACE[r].cur;
			SPACE[r]=i;
		}
		else
		{
			SPACE[p].cur=SPACE[k].cur;
			Free_SL(k);
			if(k==r)
				r=p;
		}
	}
}
