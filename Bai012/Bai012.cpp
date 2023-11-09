#include <iostream>
#include<iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktNguyenTo(int);
void LietKe(int[][100], int, int);
int main()
{
	int a[100][100];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	cout << "so nguyen to la: ";
	LietKe(a, m, n);
}
void Nhap(int a[][100], int& m, int& n)
{
	cout << "nhap so hang m: ";
	cin >> m;
	cout << "nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];

		}
}
void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << "\n";
	}
}
bool ktNguyenTo(int k)
{
	if (k <= 1)
		return false;
	int dem = 0;
	for (int i = 1; i <=k; i++)
	{
		if (k % i == 0)
			dem++;
		if (dem == 2)
			return true;
	}

	return false;
}
void LietKe(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (ktNguyenTo(a[i][j]))
				cout << setw(8) << a[i][j];
	}

}