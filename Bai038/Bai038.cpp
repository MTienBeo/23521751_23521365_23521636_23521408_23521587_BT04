#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
int kt5m(int);
void Tongchan(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, n, m);
	Xuat(a, n, m);
	Tongchan(a, n, m);
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
int kt5m(int k)
{
	if (k < 0)
		return 0;
	int flag = 1;
	int t = k;
	while (t>1)
	{
		int du = t % 5;
		if (du != 0)
			flag = 0;
		t = t / 5;
	}
	return flag;
}
void Tongchan(int a[][100], int n, int m)
{
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (kt5m(a[i][j]) == 1)
				s = s + a[i][j];
		}
	}
	cout << "Tong cac gia tri co dang 5m trong ma tran la: " << s << endl;
}