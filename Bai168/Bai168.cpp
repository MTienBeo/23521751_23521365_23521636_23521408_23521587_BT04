#include<iostream>
#include<iomanip>
using namespace std;

void TaoMaTran(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktCon(float[][100], int, int, int, int);
int DemCon(float[][100], int, int);

int main()
{
	float a[100][100];
	int n;
	int m;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	cout << "So ma tran 3x3 toan duong trong ma tran la " << DemCon(a, n, m);
	return 0;
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

int ktCon(float a[][100], int n, int m, int vtd, int vtc)
{
	int flag = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[vtd + i][vtc + j] <= 0)
				flag = 0;
		}
	}
	return flag;
}
int DemCon(float a[][100], int n, int m)
{
	int dem = 0;
	for (int vtd = 0; vtd <= m - 3; vtd++)
	{
		for (int vtc = 0; vtc <= n - 3; vtc++)
		{
			if (ktCon(a, n, m, vtd, vtc) == 1)
				dem++;
		}
	}
	return dem;
}