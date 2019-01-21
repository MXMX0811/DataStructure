#include<iostream>
using namespace std;
#define MAX_SIZE 1002
#define MAX_ROW 1002
class Trip {
public:	int row;
		int col;
		int value;
};
class MATRIX {
public:	int rn;
		int cn;
		int tn;
		Trip  data[MAX_SIZE];
		int rpos[MAX_ROW];
};
void mul(int **A, int **B, int c1, int r1, int r2) {
	int **C;
	MATRIX a;
	MATRIX b;
	a.tn = 0;
	b.tn = 0;
	a.rn = c1; 
	a.cn = r1; 
	b.rn = r1; 
	b.cn = r2;
	int p = 1; int q = 1;
	for (int i = 0; i < c1; i++) {
		for (int j = 0; j < r1; j++) {
			if (A[i][j] != 0)
			{
				a.data[p].value = A[i][j];
				a.data[p].row = i + 1;
				a.data[p].col = j + 1;
				a.tn++;
				p++;
			}
		}
	}
	for (int i = 0; i < r1; i++) {      //构建三元组
		for (int j = 0; j < r2; j++) {
			if (B[i][j] != 0)
			{
				b.data[q].value = B[i][j];
				b.data[q].row = i + 1;
				b.data[q].col = j + 1;
				b.tn++;
				q++;
			}
		}
	}

	C = new int*[c1];
	for (int i = 0; i < c1; i++)
	{
		C[i] = new int[r2];
	}
	for (int i = 0; i < c1; i++)
		for (int j = 0; j < r2; j++)
			C[i][j] = 0;//赋初值

	for (int i = 1; i <= a.tn; i++) {
		for (int j = 1; j <= b.tn; j++) {
			if (a.data[i].col == b.data[j].row)
			{
				C[(a.data[i].row) - 1][(b.data[j].col) - 1] += a.data[i].value*b.data[j].value;
			}
		}
	}


	for (int i = 0; i < c1; i++) {
		for (int j = 0; j < r2; j++) {
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
};

int main() {
	int n1, n2, n3, n4;
	cout << "请输入矩阵A的行数、列数以及矩阵B的行数、列数:";
	cin >> n1 >> n2 >> n4 >>n3;
	cout << endl;
	int **A1, **B1;
	A1 = new int*[n1];
	for (int i = 0; i < n1; i++)
	{
		A1[i] = new int[n2];
	}
	B1 = new int*[n2];
	for (int i = 0; i < n2; i++) {
		B1[i] = new int[n3];
	}
	cout << "A:" << endl;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++)
			cin >> A1[i][j];
	}
	cout << "B:" << endl;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n3; j++)
			cin >> B1[i][j];
	}
	int **AB;
	AB = new int*[n1];
	for (int i = 0; i < n1; i++) {
		AB[i] = new int[n3];
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n3; j++) {
			AB[i][j] = 0;
			for (int k = 0; k < n2; k++) {
				AB[i][j] += A1[i][k] * B1[k][j];
			}
		}
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n3; j++) {
			cout << AB[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	mul(A1, B1, n1, n2, n3);
	system("Pause");
	return 0;
}
