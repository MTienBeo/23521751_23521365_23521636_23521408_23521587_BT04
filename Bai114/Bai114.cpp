#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
bool ktChinhPhuong(int);
int ktCot(int[][500], int, int, int);
void LietKe(int[][500], int, int);

int main()
{
	int b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Cac cot co chua so chinh phuong la: ";
	LietKe(b, k, l);
	cout << endl;
	cout << "Ket thuc!!!\n\n\n";
	return 0;
}

void Nhap(int a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % (200 + 1) - 100;
		}
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(8) << a[i][j];
		cout << endl;
	}
}

bool ktChinhPhuong(int n)
{
	if (n < 0)
		return 0;
	int flag = 0;
	int i = 0;
	while (i <= n)
	{
		if (i * i == n)
			flag = 1;
		i++;
	}
	return flag;
}

int ktCot(int a[][500], int m, int n, int c)
{
	int flag = 0;
	for (int i = 0; i < m; i++)
		if (ktChinhPhuong(a[i][c]) == 1)
			flag = 1;
	return flag;
}

void LietKe(int a[][500], int m, int n)
{
	for (int j = 0; j < n; j++)
		if (ktCot(a, m, n, j) == 1)
			cout << j << " ";
}