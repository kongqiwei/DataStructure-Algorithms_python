typedef MAX_TRUE_SIZE  100
typedef char Elemtype_Sq;
typedef int Status;
typedef Elemtype_Sq SqBiTree[MAX_TRUE_SIZE];
typedef struct
{
  int level;
  int order;  //节点在本层的序号
}Position;
void InitBiTree_Sq(SqBiTree T)
{
  int i;
  for(i=0;i<MAX_TRUE_SIZE;i++)
    T[i]='\0';  //空树无节点，以空节点填充
}
void ClearBiTree_Sq(SqBiTree T)
{
  int i;
  for(i=0;i<MAX_TRUE_SIZE;i++)
    T[i]='\0';  //和构造是一样的
}
void DestroyBiTree_Sq(SqBiTree T)
{
  //二叉树无法销毁
}
Status BiTreeEmpty_Sq(SqBiTree T)
{
  return T[0]=='\0'?TRUE:FALSE;
}
Status CreateBiTree_Le_Sq(FILE *fp,SqBiTree T)
{
  char ch;
  int i=0;
  while(Scanf(fp,"%c",&ch)==1&&ch!='\n')
  {
    if(ch==' ')
      T[i++]='\0';
    else
      T[i++]=ch;
  }
  return 1;
}
Status CreateBiTree_pre_Sq(FILE *fp,SqBiTree T,int i)  
{
  char ch;
  Scanf(fp,"%c",&ch);
  if(ch==' ')
    T[i]='\0';
  else
  {
    T[i]=ch;
    CreateBiTree_pre_Sq(fp,T,2*i+1);  //完全二叉树
    CreateBiTree_pre_Sq(fp,T,2*i+2);
  }
  return 1;
}
int BiTreeLength_Sq(SqBiTree T)
{
  int len;
  for(len=MAX_TRUE_SIZE;len-1>=0;len--)
  {
    if(T[len-1]!='\0')
      break;
  }
  return len;
}
int BiTreeDepth_Sq(BiTree T)
{
  int level=0;
  while((int)pow(2,level)-1<BiTreeLength_Sq(T))  //完全二叉树的经典深度求法
    len++;
  return level;
}
Status Root_Sq(SqBiTree T,Elemtype_Sq *e)
{
  if(BiTreeEmpty_Sq(T))
    return error;
  *c=T[0];
  return  1;
}
Elemtype_Sq value_Sq(SqBiTree T,Position s)
{
  int i=(int)(pow(2,s.level-1))+s.order-2;
  return T[i];
}
Status Assign_Sq(SqBiTree T,Position s,Elemtype_Sq value)
{
  int i=(int)pow(2,s.level-1)+s.order-2;
  if(value=='\0'&&(T[2*i+1]!='\0'||T[2*i+2]!='\0'))
    return error;
  else if(value!='\0'&&T[(i+1)/2-1]=='\0')
    return error;
  else
    T[i]=value;
  return 1;
}
Elemtype_Sq parent_Sq(SqBiTree T,Elemtype_Sq e)
{
  int i;
  if(T[0]!='\0')
  {
    for(i=0;i<MAX_TRUE_SIZE;i++)
    {
      if(T[i]==e)
        return T[(i+1)/2-1];
    }
  }
  return '\0';
}
Elemtype_Sq leftchild_Sq(SqBiTree T,Elemtype_Sq e)
{
  int i;
  if(T[0]=='\0')
    return '\0';
  for(i=0;i<MAX_TRUE_SIZE;i++)
  {
    if(T[i]==e)
      return T[2*i+1];
  }
  return '\0';
}
Elemtype_Sq rightchild_Sq(SqBiTree T,Elemtype_Sq e)
{
  int i;
  if(T[0]=='\0')
    return '\0';
  for(i=0;i<MAX_TRUE_SIZE;i++)
  {
    if(T[i]==e)
      return T[2*i+2];
  }
  return '\0';
}
Elemtype_Sq leftsibing_Sq(SqBiTree T,Elemtype_Sq e)  //返回左右兄弟
{
  int i;
  if(T[0]=='\0')
    return '\0';
  for(i=0;i<MAX_TRUE_SIZE;i++)
  {
    if(T[i]==e&&i/2==0)
      return T[i-1];
  }
  return '\0';
}
Elemtype_Sq rightsibing_Sq(SqBiTree T,Elemtype_Sq e)  //返回左右兄弟
{
  int i;
  if(T[0]=='\0')
    return '\0';
  for(i=0;i<MAX_TRUE_SIZE;i++)
  {
    if(T[i]==e&&i/2==0)
      return T[i+1];
  }
  return '\0';
}
void levelOrderTraverse_Sq(SqBiTree T,void(visit)(Elemtype_Sq))
{
  int i;
  int len=BiTreeLength_Sq(T);
  for(i=0;i<len;i++)
  {
    if(T[i]!='\0')
      visit(T[i]);
  }
}
void preOrderTraverse_Sq(SqBiTree T,void(visit)(Elemtype_Sq),int i)
{
  if(T[i]!='\0')
  {
    visit(T[i]);
    preOrderTraverse_Sq(T,visit,2*i+1);
    preOrderTraverse_Sq(T,visit,2*i+2);
  }
}
void InOrderTraverse_Sq(SqBiTree T,void(visit)(Elemtype_Sq),int i)
{
  if(T[i]!='\0')
  {
    preOrderTraverse_Sq(T,visit,2*i+1);
    visit(T[i]);
    preOrderTraverse_Sq(T,visit,2*i+2);
  }
}
void postOrderTraverse_Sq(SqBiTree T,void(visit)(Elemtype_Sq),int i)
{
  if(T[i]!='\0')
  {
    preOrderTraverse_Sq(T,visit,2*i+1);
    preOrderTraverse_Sq(T,visit,2*i+2);
    visit(T[i]);
  }
}
void print_Sq(SqBiTree T)
{
  int i,j,level;
  char tmp[MAX_TRUE_SIZE][MAX_TRUE_SIZE]={};
  level=BiTreeDepth_Sq(T);
  for(i=1;i<=level;i++)
    for(j=1;j<=(int)(pow(2,i-1);j++))
      tmp[i-1][(int)pow(2,level-i)+(j-1)*(int)(pow(2,lebel-i+1)-1)]=T[(int)pow(2,i-1)-1+j-1];
    for (i = 0; i <level; i++)
    {
      for (j = 0; j < 2*(int)pow(2,level-1)-1; j++)
      {
        if(tmp[i][j]!='\0')
          printf("%c", tmp[i][j]);
        else
          printf(" ");
      }
      printf("\n\n");
    }
}
