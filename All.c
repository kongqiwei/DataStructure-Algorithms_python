//插入排序
typedef struct 
{
	int key;
}datatype;
void D_InsertSort(datatype R[],int n)
{
	int i,j;
	for(i=2;i<=n;i++)
		if(R[i].key<R[i-1].key)//小于时候才插入
		{
			R[0]=R[i];   //用R[0]存储当前操作的R[i]
			for(j=i-1;R[0].key<R[j].key;j--)
				R[j+1]=R[j];     //逐步后移元素
			R[j+1]=R[0];    //插入位置
		}
}

//希尔排序
void ShellSort(datatype R[],int n,int d[],int t)
{
	int i,j,k,h;
	for(k=0;k<t;k++)
	{
		h=d[k];  //h为第k趟的增量
		for(i=h+1;i<=n;i++)
			if(R[i].key<R[i-h].key)
			{
				R[0]=R[i];
				for(j=i-h;j>0&&R[0].key<R[j].key;j=j-h)
					R[j+h]=R[j];
				R[j+h]=R[0];
			}
	}
}
//地杰斯特拉算法
#define MaxVertexNum 100   //最大顶点数
#define MaxCost  9999      //边的最大权值
typedef char VerTextype;
typedef int  EdgeType;
typedef struct 
{
    VerTextype vexs[MaxVertexNum];//存放顶点信息
    EdgeType edges[MaxVertexNum][MaxVertexNum];//邻接矩阵，存放临接关系
    int e,n;//存放顶点数和边数   
}Mgraph;
void CreateMGraph(Mgraph *G)
{
	int i,j,k,w;
	printf("请输入定点数和边数，格式：顶点数，边数\n");
	scanf("%d%d",&(G->n),&(G->e));
	printf("请输入顶点信息\n");
	for (i=0;i<G->n;i++)
		scanf("%c",&(G->vexs[i]));
	for (i=0;i<G->n;i++)
		for (j = 0; j < G->n; j++)
			G->edges[i][j]=MaxCost;
	printf("请输入每条边对应的两个顶点的序号(输入格式为:i,j,w):\n");
	for (k=0;k<G->e;k++)
	{
		scanf("%d%d%d",&i,&n,&w);
		G->edges[i][j]=w;
	}

}
void ShortestPath(Mgraph *G,int P[],int D[])
{
	int final[MaxVertexNum],i,j,k,min;
	final[0]=1;
	D[0]=0;
	P[0]=-1;
	for(i=1;i<G->n;i++)
	{
		final[i]=0;
		D[i]=
	}


}
