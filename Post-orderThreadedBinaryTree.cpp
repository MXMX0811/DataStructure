#include<iostream>  
using namespace std;

typedef enum { Link, Thread }Pointer;
typedef struct TreeNode
{
	TreeNode(const char _data)
		: data(_data)
		, Left(NULL)
		, Right(NULL)
		, Parent(NULL)
		, Ltag(Link)
		, Rtag(Link)
	{}
	char data;
	struct TreeNode* Left;
	struct TreeNode* Right;
	struct TreeNode* Parent;//双亲  
	Pointer Ltag, Rtag;
}TreeNode;
typedef struct TreeNode *Node;

class PostThread_BiTree
{
public:
	PostThread_BiTree(const char arr[], int size)
	{
		int index = 0;
		TreeNode* parent = NULL;
		create(_pRoot, arr, size, index, parent);
	}
private:
	void create(Node &Root, const char arr[], int size, int &i, Node &parent) //先序建立树
	{
		if (arr && i < size && arr[i] != '#')
		{
			Root = new TreeNode(arr[i]);
			Root->Parent = parent;

			create(Root->Left, arr, size, ++i, Root);   
			create(Root->Right, arr, size, ++i, Root);
		}
	}
public:
	void PostTreading()
	{
		_PostThreading(this->_pRoot);
	}

	void PostOrder()
	{
		_PostOrder(this->_pRoot);
	}

private:
	Node _pRoot;
	Node Prev;

	void _PostThreading(Node &Root)
	{
		if (Root)
		{
			_PostThreading(Root->Left);
			_PostThreading(Root->Right);
			if (Root->Left == NULL)
			{
				Root->Left = Prev;
				Root->Ltag = Thread;
			}
			if (Prev && Prev->Right == NULL) 
			{
				Prev->Right = Root;
				Prev->Rtag = Thread;
			}
			Prev = Root;
		}
	}

	void _PostOrder(Node Root)
	{
		if (Root)
		{
			Node pCur = Root;
			Prev = NULL;
			while (pCur != NULL)
			{
				//去最左边的节点  
				while (pCur->Left != Prev && pCur->Ltag == Link) //左子树  
				{
					pCur = pCur->Left;
				}
				//访问后继  
				while (pCur && pCur->Rtag == Thread)
				{
					cout << pCur->data << ' ';
					Prev = pCur;
					pCur = pCur->Right;
				}
				//判断此时pCur是不是指向了根节点  
				if (pCur == Root)
				{
					cout << pCur->data << ' ';
					return;
				}
				while (pCur && pCur->Right == Prev)
				{
					cout << pCur->data << ' ';
					Prev = pCur;
					pCur = pCur->Parent;  
				}
				if (pCur && pCur->Rtag == Link)
				{
					pCur = pCur->Right;
				}
			}
		}
	}
};

void Test()
{
	char* arr = "-+a##*b##-c##d##/e##f##";
	PostThread_BiTree tree(arr, strlen(arr));  
	tree.PostTreading();
	tree.PostOrder();
}
int main()
{
	Test();
	return 0;
}
