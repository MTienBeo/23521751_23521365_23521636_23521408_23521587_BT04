#include<iostream>
#include<iomanip>
using namespace std;


void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktDang2m(int k);
void Dem(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, m, n);
	Xuat(a, m, n);
	Dem(a, m, n);
}
void TaoMaTran(int a[][100], int& m, int& n)
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
			a[i][j] = -100 + rand() % 200;
		}
	}
}
void Xuat(int a[][100], int m, int n)
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
bool ktDang2m(int k)
{
	if (k <= 0)
		return 0;
	int t = k;
	while (t > 1)
	{
		int du = t % 2;
		if (du != 0)
			return 0;
		t = t / 2;
	}
	return 1;
}
void Dem(int a[][100], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktDang2m(a[i][j]))
				dem = dem++;
		}
	}
	cout << "So luong so co dang 2m trong ma tran la: " << dem;
}