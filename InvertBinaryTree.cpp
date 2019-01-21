//输入非空结点数，按层次序输入数据，反转二叉树后以完全二叉形式按层次输出

#include<iostream>
using namespace std;

struct binarytree
{
	char data;
	binarytree *Lchild, *Rchild;
};typedef binarytree *BT;

BT invert(BT &tree)
{
	if (tree == NULL)return NULL;	       //空树
	tree->Lchild = invert(tree->Lchild);   //递归
	tree->Rchild = invert(tree->Rchild);	
	binarytree* tmp = tree->Lchild;        //左右交换
	tree->Lchild = tree->Rchild;
	tree->Rchild = tmp;
	return tree;
}

BT createBinTreeByArray(char *array, int size,int &level) 
{
	int currLevel = 1;
	int currLevelStart = 0;
	int parentLevelStart = 0;
	BT *nodeArray = (BT*)malloc(sizeof(BT) * size);      //分配空间
	while (currLevelStart < size) 
	{
		int levelN = pow(2, currLevel - 1);         //此层应有结点数
		int parentStep = 0;
		for (int step = 0; step < levelN; step++)   //遍历该层
		{
			int i = currLevelStart + step;
			if (i >= size) break;
			BT node = NULL;                              //新建结点
			if (array[i] != '*')                     //不为空建立左右子结点
			{
				node = (BT)malloc(sizeof(binarytree));
				node->data = array[i];
				node->Lchild = NULL;
				node->Rchild = NULL;
				nodeArray[i] = node;
			}
			if (currLevelStart > 0)                      //不是第一层
			{
				BT parentNode = nodeArray[parentLevelStart + parentStep];   //找到父节点
				if (step % 2 == 0)                       //确定是父节点的左孩子或右孩子
					parentNode->Lchild = node;				
				else 
				{
					parentNode->Rchild = node;
					parentStep++;
				}
			}
		}
		parentLevelStart = currLevelStart;     //下移一层
		currLevelStart += levelN;         //此层开始时的结点编号
		currLevel++;
	}
	level = currLevel - 2;           //最大层数
	BT rootNode = nodeArray[0];   //根节点
	free(nodeArray);              //释放空间
	return rootNode;
}

int printNodeAtLevel(BT root, int level, int maxlevel)   //输出某层
{
	if (level < 0)
		return 0;
	if (root->Rchild == NULL&&level != maxlevel)         //补全
	{
		
		BT newroot = new binarytree;
		newroot->data = '*';
		newroot->Lchild = NULL;
		newroot->Rchild = NULL;
		root->Rchild = newroot;
	}
	if (root->Lchild == NULL&&level != maxlevel)
	{

		BT newroot = new binarytree;
		newroot->data = '*';
		newroot->Lchild = NULL;
		newroot->Rchild = NULL;
		root->Lchild = newroot;
	}
	if ((root->Lchild) == NULL&&level==maxlevel)
	{
		cout << root->data;
		return 0;
	}
	if (level == 0)
	{
		cout << root->data;
		return 1;
	}
	printNodeAtLevel(root->Lchild, level - 1,maxlevel-1);
	printNodeAtLevel(root->Rchild, level - 1,maxlevel-1);
}

void printNodeByLevel(BT root,int maxlevel)   //按层输出
{
	for (int level = 0; ; level++)
	{
		if (!printNodeAtLevel(root, level,maxlevel))
			break;
	}
}

int main()
{
	char c;
	int s, i = 0, j = 0;      //j为非空结点数
	int maxlevel = 0;
	cout << "输入结点数:";
	cin >> s;
	char *array = new char;
	while (cin)
	{
        cin >> c;
		array[i] = c;
		i++;
		if (c != '*')j++;
		if (j == s)break;
	}
	BT rootNode = createBinTreeByArray(array, i, maxlevel);
	invert(rootNode);
	printNodeByLevel(rootNode,maxlevel);
	cout << endl;
	return 0;
}
