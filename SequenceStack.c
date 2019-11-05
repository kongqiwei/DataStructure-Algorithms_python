#define STACK_INIT_SIZE  100
#define STACKINCREMENT  10
#include<stdio.h>
#include<stdlib.h>
typedef int ELemtype_Sq;
typedef int Status;
typedef struct
{
	ELemtype_Sq *base;
	ELemtype_Sq *top;
	int stacksize;
}SqStack;

Status InitStack_Sq(SqStack *S)
{
	(*S).base=(ELemtype_Sq *)malloc(STACK_INIT_SIZE*sizeof(ELemtype_Sq));
	if(!(*S).base)
		exit(overflow);
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE;
	return 1;
}

Status DestroyStack_Sq(SqStack *S)
{
	free((*S).bese);
	(*S).base=NULL;
	(*S).top=NULL;
	(*S).stacksize=0;
	return 1;
}
Status ClearStack_Sq(SqStack *S)
{
	(*S).top=(*S).base;
	return 1;
}
Status StackEmpty_Sq(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}
int StackLength_Sq(SqStack S)
{
	return S.top-S.base;
}
Status GetTop_Sq(SqStack S,ELemtype_Sq *e)
{
	if(S.top==S.base)
		return ERROR;
	*e=*(S.top-1);
	return 1;
}
Status Push_Sq(SqStack *S,ELemtype_Sq e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base=(ELemtype_Sq *)realloc((*S).base,((*S).stacksize+STACKINCREMENT));
		if(!(*S).base)
			exit(overflow);
		(*S).top=(*S).base+(*S).stacksize;
		(*S).stacksize+=STACKINCREMENT;
	}
	*(S->top)=e;
	(S->top)++;
	return 1;
}
Status StackTraverse_Sq(SqStack S,void(visit)(ELemtype_Sq))
{
	ELemtype_Sq *p=S.base;
	while(p<S.top)
		visit(*p++);
	return 1;
}
//一些应用
//进制转化
//模拟行编辑输入
void conversion(int i)
{
	SqStack S;
	ELemtype_Sq e;
	InitStack_Sq(&S);
	printf("十进制%d转化为八进制\n",i);
	while(i)
	{
		Push_Sq(&S,i%8);
		i=i/8;
	}
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S,&e);
		printf("%d\n",e);
	}
}
void LineEdit(char Buffer[])
{
	SqStack S;
	ELemtype_Sq e;
	int i;
	char ch;
	InitStack_Sq(&S);
	i=0;
	ch=Buffer[i++];
	while(ch!='\0')
	{
		while(ch!='\0'&&ch!='\n')
		{
			switch(ch)
			{
				case '#':Pop_Sq(&S,&e);
				       break;
				case '@':ClearStack_Sq(&S);
				      break;
				default: Push_Sq(&S,ch);
			}
		}
		if(ch=='\n')
		{
				Push_Sq(&S,ch);
				StackTraverse_Sq(S,Print);
				ClearStack_Sq(&S);
				ch=Buffer[i++];
		}
	}
	if(ch=='\0')
	{
			StackTraverse_Sq(S,Print);
			DestroyStack_Sq(&S);
	}
}
void Print(ELemtype_Sq e)
{
	printf("%c",e);
}
