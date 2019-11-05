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
