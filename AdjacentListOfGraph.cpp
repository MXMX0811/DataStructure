#include<iostream>
using namespace std;
#define MAX_VEX 30 
typedef struct LinkNode
{ 
	int adjvex;// 邻接点在头结点数组中的位置(下标)
	char data;
    struct LinkNode *nextarc;
}LinkNode; 
typedef struct VexNode
{ 
	char data; 
    LinkNode *firstarc; 
}VexNode; 
typedef struct
{ 
	int vexnum, arcnum;
    VexNode AdjList[MAX_VEX];
}ALGraph; /* 图的结构定义*/

void create(ALGraph *G)
{
	int x, y;
	cout << "输入顶点数：";
	cin >> G->vexnum;
	cout << "输入边数：";
	cin >> G->arcnum;
	LinkNode *N = NULL;
	for (int i = 1; i <= G->vexnum; i++)
	{
		G->AdjList[i].data = i + '0';
		G->AdjList[i].firstarc = NULL;
	}
	cout << "输入边的起点和终点：" << endl;
	for (int i = 1; i <= G->arcnum; i++)
	{
		cin >> x >> y;
		N = new LinkNode;
		if (N == NULL)
			return;
		N->adjvex = y;
		N->nextarc = G->AdjList[x].firstarc;
		G->AdjList[x].firstarc = N;
	}
}
void print(ALGraph *G)
{
	int n = G->vexnum;
	LinkNode *N = NULL;
	int i;
	for (i = 1; i <= G->vexnum; i++)
	{
		N = G->AdjList[i].firstarc;
		if (N == NULL)
			cout << "没有从结点" << G->AdjList[i].data << "出发的边" << endl;
		else
		{
			cout << "从结点" << G->AdjList[i].data << "出发的边" << endl;
			while (N != NULL)
			{
				cout << G->AdjList[i].data << "->" << G->AdjList[N->adjvex].data << endl;
				N = N->nextarc;
			}
		}
	}
}
void Delete(ALGraph *G, char x)
{
	LinkNode *N = NULL;
	int j;
	for (int i = 1; i <= G->vexnum; i++) 
	{
		if (G->AdjList[i].data == x)
		{
			for (int j = i; j + 1 <= G->vexnum; j++)
				G->AdjList[j] = G->AdjList[j + 1];
			(G->vexnum)--;
			break;
		}
	}
	for (int i = 1; i <= G->vexnum; i++)
	{
		N = G->AdjList[i].firstarc;
		while (1)
		{
			if (N == NULL || N->nextarc == NULL)
				break;
			if (N->nextarc->data == x)
			{
				N->nextarc = N->nextarc->nextarc;
				break;
			}
			N = N->nextarc;
		}
	}
}
int main()
{
	ALGraph *G = new ALGraph;
	char x;
	create(G);
	print(G);
	cout << "输入要删除的结点值:";
	cin >> x;
	Delete(G, x);
	print(G);
	return 0;
}
