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
//迷宫操作
#include<stdio.h>
#include<stdlib.h>
#include<ctime.h>
#define N  15
#define X  4
#define SleepTime 2
typedef enum //枚举类型
{
	Wall,
	Obstacle,
	Way,
	DeadLock,
	East,
	South,
	West,
	North
}MazeNode;
typedef struct 
{
	int x;
	int y;
}PosType;
typedef struct
{
	int ord;
	PosType seat;
	int di;
}ElemType_Sq;
typedef int Mazetype;
typedef int Status;
Status  MazePath(Mazetype maze[][N],PosType start,PosType end)
{
	SqStack S;
	ElemType_Sq nodeInf;
	PosType curPos;
	int curStep;
	InitStack_Sq(&S);
	curPos=start;
	curStep=1;
	do
	{
		if(Pass(curPos,maze))
		{
			FootPrint(curPos,maze);
			ShowMaze(maze);
			SetElemType(&nodeInf,curStep,curPos,East);
			Push_Sq(&S,nodeInf);
			if(EqualPosType(curPos,end))
			{
				printf("寻路成功\n");
				return TRUE;
			}
			curPos=NextPos(curPos,East);
			curStep++;
		}
		else
		{
			if(!StackEmpty_Sq(S))
			{
				Pop_Sq(&S,&nodeInf);
				while(nodeInf.di==North&&!StackEmpty_Sq(S))
				{
					MarkPrint(nodeInf.seat,maze);
					ShowMaze(maze);
					Pop_Sq(&S,&nodeInf);
				}
				if(nodeInf.di<North)
				{
					maze[nodeInf.seat.x][nodeInf.seat.y]=++nodeInf.di;
					ShowMaze(maze);
					Push_Sq(&S,nodeInf);
					curPos=NextPos(nodeInf.seat,nodeInf.di);
				}
			}
		}
	}while(!StackEmpty_Sq(S));
	printf("寻路失败\n");
	return FALSE;
}
void InitMaze(MazeType maze[][N],PosType *start,PosType *end)
{
	int i,j,tmp;
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i==0||j==0||i==N-1||j==N-1)
				maze[i][j]=Wall;
			else
			{
				tmp=rand()%X;
				if(tmp)
					maze[i][j]=Obstacle;
				else
					maze[i][j]=Way;
			}
		}
	}
	(*start).x=1;
	(*start).y=0;
	(*end).x=N-2;
	(*end).y=N-1;
	maze[1][0]=maze[N-2][N-1]=Way;
	maze[1][1]=maze[N-2][N-2]=Way;
}
void PaintMaze(Mazetype maze[][N])
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(maze[i][j]==Wall)
				printf("fucked\n");
			else if(maze[i][j]==Obstacle)
				printf("fukced\n");
			else if(maze[i][j]==East)
				printf(">\n");
			else fi (maze[i][j]==South)
				printf("'\n",);
			else if (maze[i][j]==West)
				printf("<\n" );
			else  if (maze[i][j]==North)
				printf("^\n");
			else
				printf("  \n");
			if(j!=0&&j%(N-1)==0)
				printf("n\n");
		}
}
void ShowMaze(MazeType maze[][N])
{
	Wall(SleepTime);
	system("cls");
	PaintMaze(maze);
}
Status EqualPosType(PosType seat1,PosType seat2)
{
	if(seat1.x==seat2.x&&seat1.y==seat2.y)
		return TRUE;
	else
		return FALSE;
}
Status Pass(PosType seat,MazeType maze[][N])
{
	int x=seat.x;
	int y=seat.y;
	if(!IsCross(seat)&&maze[x][y]==Way)
		return TRUE;
	else
		return FALSE;
}
void  FootPrint(PosType seat,MazeType maze[][N])
{
	maze[seat.x][seat.y]=East;
}
void SetElemType(ElemType_Sq *e,int ord,PosType seat,int di)
{
	(*e).ord=ord;
	(*e).seat=seat;
	(*e).di=di;
}
PosType NextPos(PosType seat,int di)
{
	PosType tmp=seat;
	switch(di)
	{
		case East:tmp.y++;break;
		case West:tmp.y--;break;
		case South:tmp.x++;break;
		case North:tmp.x--;break;
	}
	return tmp;
}
Status IsCross(PosType seat)
{
	int x=seat.x;
	int y=seat.y;
	if(x<0||y<0||x>N-1||y>N-1)
		return TRUE;
	else
		return FALSE;
}
void MarkPrint(PosType seat,MazeType maze[][N])
{
	int x=seat.x;
	int y=seat.y;
	maze[x][y]=koDeadLock;
}

//表达式求值
typedef char ElemType_Sq;
typedef ElemType_Sq OperandType;
typedef ELemtype_Sq OperatorType
OperandType EvaluateExpression(char exp[])
{
	SqStack OPTR,OPND;
	ElemType_Sq e,ch;
	OperatorType theta,x;
	OperandType a,b;
	int i;
	InitStack_Sq(&OPTR);
	Push_Sq(&OPTR,"#");
	InitStack_Sq(OPND);
	i=0;
	ch=exp[i++];
	while(ch!='#'||GetTop_OPTR(OPTR)!='#')
	{
		if(!IN(ch))
		{
			Push_Sq(&OPND,ch);
			ch=exp[i++];
		}
		else
		{
			switch(Precede(GetTop_OPTR(OPTR),ch))
			{
				case '<':
				   Push_Sq(&OPTR,ch);
				   ch=exp[i++];
				   break;
				case '=':
				   Pop_Sq(&OPTR,&x);
				   ch=exp[i++];
				   break;
				case '>':
				    Pop_Sq(&OPTR,&theta);
				    Pop_Sq(&OPND,&b);
				    Pop_Sq(&OPND,&a);
				    break;
			}
		}
	}
	return GetTop_OPTR(OPND);
}
OperatorType GetTop_OPTR(SqStack OPTR)
{
	ElemType_Sq e;
	GetTop_Sq(OPTR,&e);
	return e;
}
Status In(ElemType_Sq c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '#':
		    return TRUE;
		default:
		    return FALSE;
	}
}
OperatorType Precede(OperatorType o1,OperatorType o2)
{
	OperatorType f;
	switch (o2)；
	{
		case'+':
		case'-':
		  if(o1=='('||o1=='#')
			 f='<';
		  else
			 f='>';
		  break;
		case '*':
		case '/':
		   if(o1=='*'||o1=='/'||o1==')')
		   	    f='>';
		   	else
		   		f='<';
		   	    break;
		case '(':
			if(o1==')')
			{
				printf("括号匹配错误\n");
				exit(ERROR);
			}
			else
				f='<';
			break;
		case')':
		    switch(o1)
		    {
		    	case'(':
		    	     f='=';
		    	     break;
		    	case '#':
		    	      printf("输入错误\n");
		    	    exit(ERROR);
		    	 default:
		    	     f='>';
		    }
		    break;

		 case '#':
		    switch(o1)
		    {
		    	case'#':
		    	   f='=';
		    	   break;
		    	case '(':
		    	   printf("输入错误\n");
		    	   break;
		    	 default:
		    	    f='>';
		    }
	}
	return f;
}
OperandType(operate(OperandType a,OperatorType theta,OperandType b)
{
	int x,y,z;
	x=a-48
	y=b-48;
	switch(theta)
	{
		case '+':
		    return x+y+48;
		    break;
		case '-':
		     return x-y+48;
		     break;
		case '*':
		     return x*y+48;
		     break;
		case '/':
		     return x/y+48;
		     break;
	}
}

