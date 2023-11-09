#include<iostream>
#include<iomanip>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void BienDoi(float[][100], int, int);

int main()
{
	float a[100][100];
	int n;
	int m;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	BienDoi(a, n, m);
	Xuat(a, n, m);
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
		{
			a[i][j] = -100.0 + (rand() / (RAND_MAX / 200.0));
		}
	}
}

void Xuat(float a[][100], int n, int m)
{
	cout << "Ma tran " << m << " x " << n << " la: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8) << setprecision(5) << a[i][j];
		}
		cout << endl;
	}
}
void BienDoi(float a[][100], int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = abs(a[i][j]);
		}
	}
}

