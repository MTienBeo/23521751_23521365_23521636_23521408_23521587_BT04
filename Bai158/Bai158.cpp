#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void DichChuyenDong(int[][100], int, int, int);
void DichChuyen(int[][100], int, int);

int main()
{
	int a[100][100];
	int n;
	int m;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	DichChuyen(a, n, m);
	Xuat(a, n, m);
}

void TaoMaTran(int a[][100], int& n, int& m)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = -100 + rand() % 200;
	}
}
void Xuat(int a[][100], int n, int m)
{
	cout << "Ma tran " << m << " x " << n << " :" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
}
void DichChuyenDong(int a[][100], int n, int m, int d)
{
	int temp = a[d][n - 1];
	for (int j = n; j >= 1; j--)
		a[d][j] = a[d][j - 1];
	a[d][0] = temp;
}
void DichChuyen(int a[][100], int n, int m)
{
	for (int i = 0; i < m; i++)
		DichChuyenDong(a, n, m, i);
}