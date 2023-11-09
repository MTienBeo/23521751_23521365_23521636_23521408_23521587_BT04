#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktNguyento(int);
int Demdong(int[][100], int, int);
void Dongnhieunhat(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	Dongnhieunhat(a, n, m);
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

bool ktNguyento(int n)
{
	if (n < 0)
		return false;
	int dem = 0;
	int i = 1;
	while (i <= n)
	{
		if (n % i == 0)
			dem++;
		i++;
	}
	if (dem == 2)
		return true;
	else
		return false;
}
int Demdong(int a[][100], int i, int n)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
	{
		if (ktNguyento(a[i][j]))
			dem++;
	}
	return dem;
}
void Dongnhieunhat(int a[][100], int m, int n)
{
	int lc = Demdong(a, 0, n);
	int d;
	for (int i = 0; i < m; i++)
	{
		if (lc < Demdong(a, i, n))
		{
			lc = Demdong(a, i, n);
			d = i;
		}
	}
	cout << "Dong co nhieu so nguyen to nhieu nhat trong ma tran la: " << d;
}
