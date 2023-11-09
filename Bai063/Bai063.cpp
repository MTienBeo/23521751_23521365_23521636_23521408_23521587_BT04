#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void Dem(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	Dem(a, n, m);
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
void Dem(int a[][100], int n, int m)
{
	int c;
	cout << "Nhap cot can dem cac gia tri am: ";
	cin >> c;
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i][c] < 0)
			dem++;
	}
	cout << "So luong chu so am trong cot " << c << " la: " << dem << endl;
}