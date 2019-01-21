#include<iostream>

using namespace std;

struct doublenode   //结点
{
	int data;
	struct doublenode *pre;
	struct doublenode *next;
};

class Josephus
{
public:
	Josephus();   //构造函数            
	void add(int data);   //添加数据
	int getLength();
	int clockwise(int step);
	int anticlockwise(int step);
private:
	struct doublenode *head;
	struct doublenode *curr;
	int size;
};

Josephus::Josephus()
{
	head = curr = NULL;
	size = 0;
}

void Josephus::add(int data)   //总将新结点加至表尾
{
	struct doublenode *dn = new struct doublenode[1];
	dn->data = data;   //给新结点赋值
	if (head != NULL)   //链表不为空
	{
		curr->next = dn;   //现有结点的下一结点
		dn->pre = curr;    //新结点的前一结点
		dn->next = head;   //新结点的下一结点（循环）
		head->pre = dn;
	}
	else   //链表为空
	{
		head = dn;   //赋值给头并指向自己
		head->data = data;
		head->next = head->pre = head;
	}
	curr = dn;
	size++;
}

int Josephus::clockwise(int step)   //顺时针
{
	for (int i = 0; i < step; i++)   //移至所需位置
		curr = curr->next;
	cout << curr->data << " ";   //输出此数据
	curr = curr->next;   //顺时针后移一位
	curr->pre = curr->pre->pre;
	curr->pre->next = curr;
	size--;
	return 0;
}

int Josephus::anticlockwise(int step)   //逆时针同上
{
	for (int i = 0; i < step; i++)
		curr = curr->pre;
	cout << curr->data << " ";
	curr = curr->pre;   //逆时针前移一位
	curr->next = curr->next->next;
	curr->next->pre = curr;
	size--;
	return 0;
}

int Josephus::getLength()
{
	return size;
}

int main()
{
	Josephus a;
	int n, k, m, t;   //n为人数，k为起始位置，m为顺时针，t为逆时针
	cout << "input n:" << endl;
	cin >> n;
	cout << "input k:" << endl;
	cin >> k;
	cout << "input m:" << endl;
	cin >> m;
	cout << "input t:" << endl;
	cin >> t;
	for (int i = 1; i < n + 1; i++)   //大小为n的链表
		a.add(i);
	a.clockwise(k + m - 1);
	while (a.getLength() != 0)
	{
		a.anticlockwise(t - 1);
		if (a.getLength() == 0) break;
		a.clockwise(m - 1);
	}
	return 0;
}
