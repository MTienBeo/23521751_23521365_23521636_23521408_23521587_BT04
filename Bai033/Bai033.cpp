#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void Tongdong(int[][100], int, int, int&);

int main()
{
	int a[100][100];
	int m;
	int n;
	int c;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	Tongdong(a, n, m, c);
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
void Tongdong(int a[][100], int n, int m, int& c)
{
	int s = 0;
	cout << "Nhap so dong can tinh tong trong ma tran: ";
	cin >> c;
	for (int j = 0; j < m; j++)
	{
		s = s + a[c][j];
	}
	cout << "Tong cac gia tri tren dong " << c << " la: " << s << endl;
}