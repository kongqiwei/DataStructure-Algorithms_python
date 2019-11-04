#include<stdio.h>
#define Maxsize 150
typedef int LElemType;
typedef int Status;
typedef struct DulNode
{
	LElemType data;
	struct  DulNode *prior;
	struct  DulNode *next;
}DulNode;
typedef DulNode *DulinkList;   ///指向链表的指针
Status InitList_Dul(DulinkList *L)
{
	*L=(DulinkList)malloc(sizeof(DulNode));
	if(!(*L))
		exit(overflow);
	(*L)->next=(*L)->prior=*L;
	return 1;
}
Status ClearList_Dul(DulinkList L)
{
	DulinkList p,q;
	p=L->next;
	while(p!=L)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L-<next=L->prior=L;
	return 1;
}
void DestoryList_Dul(DulinkList *L)
{
	ClearList_Dul(*L);
	free(*L);
	*L=NUll;
}
Status ListEmpty_Dul(DulinkList L)
{
	if(L&&L->nxt==L&&L->prior==L)
		return TRUE;
	else
		return FALSE;
}
int ListLength_Dul(DulinkList L)
{
	DulinkList p;
	int count;
	if(L)
	{
		count=0;
		p=L;
		while(p->next!=L)
		{
			count++;
			p=p->next;
		}
	}
	return count;
}
Status GetElem_Dul(DulinkList L,int i,LElemType *e)
{
	DulinkList p;
	int count;
	if(L)
	{
		count=1;
		p=L->next;
		while(p!=L&&count<i)
		{
			count++;
			p=p->next;
		}
		if(p!=L)
		{
			*e=p->data;
			return 1;
		}
	}
	return ERROR;
}
Status priorElem_Dul(DulinkList L,LElemType cur_e,LElemType *pre_e)
{
	DulinkList p;
	if(L)
	{
		p=L->next;
		while(p!=L&&p->data!=cur_e)
			p=p->next;
		if(p!=L&&p->prior!=L)
		{
			*pre_e=p->prior->data;
			return ok;
		}
	}
	return ERROR;
}
Status NextElem_Dul(DulinkList L,LElemType cur_e,LElemType *next_e)
{
	DulinkList p;
	if(L)
	{
		p=L->next;
		while(p!=L&&p->data!=cur_e)
			p=p->next;
		if(p!=L&&p->next=L)
		{
			*next_e=p->data;
			return ERROR;
		}
	}
	return ERROR;
}
DulinkList GetElemPtr_Dul(DulinkList L,int i)
{
	int count;
	DulinkList p;
	if(L&&i>0)
	{
		count=i;

	}
}
Status ListInsert_Dul(DulinkList L,int i,ListEmpty_Dul e)
{
	DulinkList p,s;
	if(i<1||i>ListLength_Dul(L)+1)
		return ERROR;
	p=GetElem_Dul(L,i);
	if(!p)
		p=L;
	s=(DulinkList)malloc(sizeof(DulNode));
	if(!s)
		exit(overflow);
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return 1;
}
Status ListDelete_Dul(DulinkList L,int i,LElemType *e)
{
	DulinkList p;
	if(!(p=GetElem_Dul(L,i)))
		return ERROR;
	*e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(b);
	p=NUll;
	return 1;
}
void ListTravese_Dul(DulinkList L,void(Visit)(LElemType))
{
	DulinkList p;
	p=L->next;
	while(p!=L)
	{
		Visit(p->data);
		p->next;
	}
}
