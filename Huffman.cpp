#include<iostream>
using namespace std;
#define MAXBIT 100
#define MAXVALUE 10000.0
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1

typedef struct
{ 
	double Weight; /* 权值域*/
    int Parent , Lchild, Rchild;
	char value;
} HTNode;

typedef struct
{
	int bit[MAXBIT];
    int start;
} CODE;

void HuffmanTree(HTNode node[MAXNODE], int n)
{
	int i, j, num1, num2; //依次为循环变量、最小权值、最小权值对应序号
	double min1, min2;
	for (i = 0; i < 2 * n -1; i++) //初始化
	{
		node[i].Weight = 0.0;
		node[i].Parent = -1;
		node[i].Lchild = -1;
		node[i].Rchild = -1;
		node[i].value = i + 97; //从a开始按顺序赋值
	}
	for (i = 0; i < n; i++)
	{
		cout << "请输入字符" << node[i].value << "出现的概率:";
		cin >> node[i].Weight;
	}
	for (i = 0; i < n - 1; i++) //建树，遍历所有节点
	{
		min1 = min2 = MAXVALUE;
		num1 = num2 = 0;
		for (j = 0; j < n + i; j++) //找出权值最小且无父结点的两个结点，合并成树成为第n+i个结点
		{
			if (node[j].Weight < min1 && node[j].Parent == -1)
			{
				min2 = min1;  //min1变为第二小的
				num2 = num1;
				min1 = node[j].Weight;
				num1 = j;
			}
			else if (node[j].Weight < min2 && node[j].Parent == -1)
			{
				min2 = node[j].Weight;
				num2 = j;
			}
		}
		node[num1].Parent = n + i; //合并成为新树Parent，位置在n+i
		node[num2].Parent = n + i;
		node[n + i].Weight = node[num1].Weight + node[num2].Weight;
		node[n + i].Lchild = num1;
		node[n + i].Rchild = num2;
	}
}

int main()
{
	HTNode T[MAXNODE];
	CODE C[MAXLEAF], temp;
	int n, i, j, c, p;
	cout << "输入字符数目，字符顺序生成;";
	cin >> n;
	HuffmanTree(T, n);
	
	for (i = 0; i < n; i++)
	{
		temp.start = n - 1;
		c = i;
		p = T[c].Parent;
		while (p != -1) //有父结点时
		{
			if (T[p].Lchild == c)
				temp.bit[temp.start] = 0;
			else
				temp.bit[temp.start] = 1;
			temp.start--; //向上一层
			c = p;
			p = T[c].Parent;
		}
		for (j = temp.start + 1; j < n; j++)
			C[i].bit[j] = temp.bit[j];
		C[i].start = temp.start;
	}
	for (i = 0; i < n; i++)
	{
		cout << T[i].value << " ";
		for (j = C[i].start + 1; j < n; j++)
			cout << C[i].bit[j];
		cout << endl;
	}
}
