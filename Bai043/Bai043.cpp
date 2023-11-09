#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
void Tich(int[][100], int, int, int& c);

int main()
{
	int a[100][100];
	int m;
	int n;
	int c;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	Tich(a, n, m, c);
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
void Tich(int a[][100], int n, int m, int& c)
{
	cout << "Nhap cot can tinh tich cac gia tri duong: ";
	cin >> c;
	int t = 1;
	for (int i = 0; i < m; i++)
	{
		if (a[i][c] > 0)
			t = t* a[i][c];
	}
	cout << "Tich cac gia tri duong trong cot "<<c<<" la: " << t << endl;
}