#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktCucTieu(float[][100], int, int, int, int);
void Lietke(float[][100], int, int);

int main()
{
	float a[100][100];
	int m;
	int n;
	int c;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	Lietke(a, n, m);
}

void TaoMaTran(float a[][100], int& n, int& m)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = -100.0 + (rand() / (RAND_MAX / 200.0));
	}

}
void Xuat(float a[][100], int n, int m)
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
int ktCucTieu(float a[][100], int m, int n, int d, int c)
{
	int flag = 1;
	for (int di = -1; di <= 1; di++)
	{
		for (int dj = -1; dj <= 1; dj++)
		{
			if (d + di >= 0 && d + di < m && c + dj >= 0 && c + dj < n && (!(di == 0 && dj == 0)) && a[d + di][c + dj] < a[d][c])
				flag = 0;	
		}
	}
	return flag;
}
void Lietke(float a[][100], int n, int m)
{

	cout << "Cac gia tri cuc tieu trong ma tran la: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktCucTieu(a, m, n, i, j) == 1)
				cout << setw(9) << setprecision(5) << a[i][j];
		}

	}
}