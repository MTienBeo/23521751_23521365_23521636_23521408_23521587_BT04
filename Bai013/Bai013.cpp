#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void Lietkechan(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	Lietkechan(a, n, m);
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
void Lietkechan(int a[][100], int n, int m)
{
	cout << "Cac gia tri chan trong ma tran: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0)
				cout << setw(4) << a[i][j];
		}

	}
}