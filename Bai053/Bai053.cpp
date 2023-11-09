#include<iostream>
#include<iomanip>
using namespace std;

void TaoMaTran(int[][100], int&, int&);
void Xuat(int[][100], int, int);
bool ktChinhPhuong(int);
void DemChinhPhuong(int[][100], int, int);

int main()
{
	int a[100][100];
	int m;
	int n;
	TaoMaTran(a, m, n);
	Xuat(a, m, n);
	DemChinhPhuong(a, m, n);
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
			a[i][j] = -100 + rand() / 200;
	}
}
void Xuat(int a[][100], int m, int n)
{
	cout << "Ma tran " << m << " x " << n << " :" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << a[i][j];
		
		}	
		cout << endl;
	}
}
bool ktChinhPhuong(int k)
{
	if (k <= 0)
		return 0;
	int i = 1;
	while (i < k)
	{
		if (i * i == k)
			return 1;
		i++;
	}
	return 0;
}
void DemChinhPhuong(int a[][100], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktChinhPhuong(a[i][j]))
				dem = dem + 1;
		}
	}
	cout << "So luong so chinh phuong trong ma tran la: " << dem;
}
