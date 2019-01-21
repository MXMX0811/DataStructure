#include <string>
#include<iostream>
using namespace std;

//测试数据
//{6-[(5-4)-(10-4)/3]-[10-(8+2)*6]}/4-6*3)

struct sqstack
{
	char stack_array[100];
	int top, bottom;
};

sqstack Init_Stack()
{
	sqstack S;
	S.bottom = S.top = 0;
	return S;
}

void push(sqstack *S, char e)
{
	if (S->top != 99)
	{
		S->stack_array[S->top] = e;
		S->top++;
	}
}



int main()
{
	sqstack s = Init_Stack();
	char c;
	while ((c = getchar()) != '\n')
		push(&s, c);
	for (int i = 0; i < s.top; i++)
	{
		if (s.stack_array[i] == '{')
		{
			for (int j = i+1 ; j<=s.top-1; j++)
			{
				if (s.stack_array[j] == '}') {
					cout << i << " " << j << endl;
					s.stack_array[j] = '0';
					s.stack_array[i] = '0';
					break;
				}
				if (j == s.top-1) cout << "未匹配 " << i << endl;
			}
		}
		if (s.stack_array[i] == '[')
		{
			for (int j = i + 1; j <= s.top - 1; j++)
			{
				if (s.stack_array[j] == ']') {
					cout << i << " " << j << endl;
					s.stack_array[j] = '0';
					s.stack_array[i] = '0';
					break;
				}
				if (j == s.top - 1) cout << "未匹配 " << i << endl;
			}
		}
		if (s.stack_array[i] == '(')
		{
			for (int j = i + 1; j <= s.top - 1; j++)
			{
				if (s.stack_array[j] == ')') {
					cout << i << " " << j << endl;
					s.stack_array[j] = '0';
					s.stack_array[i] = '0';
					break;
				}
				if (j == s.top - 1) cout << "未匹配 " << i << endl;
			}
		}
		if(s.stack_array[i]==')'|| s.stack_array[i] == ']'|| s.stack_array[i] == '}')
			cout << "未匹配 " << i << endl;
	}

	return 0;
}
