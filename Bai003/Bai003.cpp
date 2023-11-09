#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void NhapMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
}

void NhapMaTran(int a[][100], int& n, int& m)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
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