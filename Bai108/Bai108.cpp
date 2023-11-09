#include<iostream>
#include<iomanip>
using namespace std;


void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktDong(int [][100], int, int, int );
void Lietke(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, m, n);
	Xuat(a, m, n);
	Lietke(a, m, n);
}
void TaoMaTran(int a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = -100 + rand() % 200;
		}
	}
}
void Xuat(int a[][100], int m, int n)
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
bool ktDong(int a[][100], int n, int m, int d)
{	
	int flag = 0;
	for (int j = 0; j < n; j++)
	{

		if (a[d][j] % 2 == 0)
			flag = 1;
		
	}
	return flag;
}
void Lietke(int a[][100], int m, int n)
{
	int dem = 0;
	cout << "Cac dong co chua gia tri chan trong ma tran la: ";
	for (int i = 0; i < m; i++)
	{
		if (ktDong(a, m, n, i))
			cout << setw(8) << i;
	}
}