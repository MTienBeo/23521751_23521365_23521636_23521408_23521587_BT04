#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktNguyenTo(int);
bool ktChinhPhuong(int);
int ktDong(int[][100], int, int, int);
void XoaDong(int[][100], int , int&, int);
void XoaDong(int[][100], int, int&);


int main()
{
	int a[100][100];
	int n;
	int m;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	XoaDong(a, n, m);
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
bool ktNguyenTo(int k)
{
	if (k <= 1)
		return false;
	int dem = 0;
	for (int i = 1; i <= k; i++)
	{
		if (k % i == 0)
			dem++;
	
	}	
	return (dem == 2);
}
bool ktChinhPhuong(int k)
{
	if (k <= 0)
		return false;
	int i = 1;
	while (i <= k)
	{
		if (i * i == k)
			return true;
		i++;
	}
	return false;
}
int ktDong(int a[][100], int n, int m, int d)
{
	int flag1 = 0;
	int flag2 = 0;
	for (int j = 0; j < n; j++)
	{
		if (ktNguyenTo(a[d][j]))
			flag1 = 1;
		if (ktChinhPhuong(a[d][j]))
			flag2 = 1;
	}
	return ((flag1 == 1)&&(flag2==1));
}
void XoaDong(int a[][100], int n, int& m, int d)
{
	for (int i = d; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = a[i + 1][j];
		}
	}
	m--;
}
void XoaDong(int a[][100], int n, int &m)
{
	for (int i = m-1; i >=0; i--)
	{
		if (ktDong(a, n, m, i) == 1)
			XoaDong(a, n, m, i);
	}
}