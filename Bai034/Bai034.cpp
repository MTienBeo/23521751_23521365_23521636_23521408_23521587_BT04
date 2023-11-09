#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
int ktNguyenTo(int);
int TongNguyenTo(int[][500], int, int, int);

int main()
{
	int b[500][500];
	int k, l, n;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Nhap hang d: ";
	cin >> n;
	cout << "Tong cac so nguyen to tren hang " << n << " la: ";
	cout << TongNguyenTo(b, k, l, n);
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

int ktNguyenTo(int n)
{
	int i = 1;
	int dem = 0;
	while (i <=n)
	{
		if (n % i == 0)
			dem++;
		i++;
	}
	if (dem == 2)
		return 1;
	return 0;
}

int TongNguyenTo(int a[][500], int m, int n, int h)
{
	int s = 0;
		for (int j = 0; j < n; j++)
			if (a[h][j] > 0 && a[h][j] != 0)
			{
				if (ktNguyenTo(a[h][j]) == 1)
					s = s + a[h][j];
			}
	return s;
}