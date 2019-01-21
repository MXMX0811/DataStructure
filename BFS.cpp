#include<iostream>
#define INFINITY 10000
#define MAX_VEX 30
using namespace std;

typedef enum { FALSE , TRUE } BOOLEAN;
BOOLEAN Visited[MAX_VEX];
typedef struct Queue
{ 
	int elem[MAX_VEX];
    int front , rear;
}Queue;
typedef struct Graph
{
	int vexnum, arcnum;
	int vexs[MAX_VEX];
	int Matrix[MAX_VEX][MAX_VEX];
}Graph;
typedef Graph* GRA;


void InitQueue(Queue* Q)
{
	Q->front = MAX_VEX - 1;
	Q->rear = MAX_VEX - 1;
}
int EnQueue(Queue* Q, int i)
{
	if (Q->front == (Q->rear + 1) % MAX_VEX)
	{
		cout << "Overflow!" << endl;
		return 0;
	}
	else
	{
		Q->rear = (Q->rear + 1) % MAX_VEX;
		Q->elem[Q->rear] = i;
		return 1;
	}
}
int EmptyQueue(Queue Q)
{
	if (Q.rear == Q.front)
		return 1;
	return 0;
}
int DeQueue(Queue* Q,int i)
{
	if (Q->front==Q->rear)
		return 0;
	else
	{
		i = Q->elem[Q->front];
		Q->front = (Q->front + 1) % MAX_VEX;
		return 1;
	}
}
void BFS_traverse(GRA G)
{
	Queue Q;
	for (int i = 0; i < G->vexnum; i++)
		Visited[i] = FALSE;
	InitQueue(&Q);
	for (int i = 0; i < G->vexnum;i++)
		if (!Visited[i])
		{
			Visited[i] = TRUE;
			cout << G->vexs[i] << " ";
			EnQueue(&Q, i);
			while (!EmptyQueue(Q))
			{
				DeQueue(&Q, i);
				for (int j = 0; j < G->vexnum; j++)
					if (G->Matrix[i][j] != INFINITY && !Visited[j])
					{
						Visited[j] = TRUE;
						cout << G->vexs[j] << " ";
						EnQueue(&Q, j);
					}
			}
		}
}
void CreateGraph(GRA G)
{
	int i, j;
	G->vexnum = 6;
	G->arcnum = 10;
	for (i = 0; i < G->vexnum; i++)
		G->vexs[i] = i + 1;
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->Matrix[i][j] = INFINITY;
		}
	}
	G->Matrix[0][1] = 5;
	G->Matrix[0][3] = 7;
	G->Matrix[0][5] = 1;
	G->Matrix[1][5] = 2;
	G->Matrix[1][4] = 10;
	G->Matrix[1][3] = 5;
	G->Matrix[1][2] = 4;
	G->Matrix[2][3] = 4;
	G->Matrix[3][4] = 6;
	G->Matrix[4][5] = 8;
	for (i = 0; i < G->vexnum; i++)	
		for (j = i; j < G->vexnum; j++)		
			G->Matrix[j][i] = G->Matrix[i][j];
}
int main()
{
	Graph G;
	CreateGraph(&G);
	BFS_traverse(&G);
	return 0;
}
