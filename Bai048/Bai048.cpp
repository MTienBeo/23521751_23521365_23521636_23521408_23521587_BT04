#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void Tich(int[][100], int, int);
bool ktChinhphuong(int);
int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	Tich(a, n, m);
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
bool ktChinhPhuong(int k)
{
	if (k <= 0)
		return 0;
	int i = 1;
	while (i < k)
	{
		if (i* i == k)
			return 1;
		i++;
	}
	return 0;
}
void Xuat(int a[][100], int n, int m)
{
	cout << "Ma tran " << n << " x " << m << ": " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(5);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void Tich(int a[][100], int n, int m)
{
	int s = 0;
	for (int j = 0; j <= n - 2; j++)
	{
		if (ktChinhPhuong(a[0][j]))
			s = s + a[0][j];
	}
	for (int i = 0; i <= m - 2; i++)
	{
		if (ktChinhPhuong(a[i][n-1]))
			s = s + a[i][n-1];
	}
	for (int j = n-1; j >= 1; j--)
	{
		if (ktChinhPhuong(a[m-1][j]))
			s = s + a[m-1][j];
	}
	for (int i = m-1; i >= 1; i--)
	{
		if (ktChinhPhuong(a[i][0]))
			s = s + a[i][0];
	}
	cout << "Tong cac so chinh phuong nam tren bien cua ma tran la: " << s;
}