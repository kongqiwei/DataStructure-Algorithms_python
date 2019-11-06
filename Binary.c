typdef char elemType;
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
  BiTree rchild;
  int n;  //当前节点的次序
}Node;  //存储当前节点信息
void ClearBiTree(BiTree *T)
{
  
}
