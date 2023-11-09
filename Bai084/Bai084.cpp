#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
int NguyenToDau(int[][500], int, int);
int NguyenToLonNhat(int[][500], int, int);

int main()
{
	int b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "So nguyen to lon nhat la: ";
	cout << NguyenToLonNhat(b, k, l);
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
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cout << fixed << setw(8) << a[i][j];
		cout << endl;
}

int ktNguyenTo(int n)
{
	int dem = 0;
	int i = 1;
	while (i <= n)
	{
		if (n % i == 0)
			dem++;
		i++;
	}
	if (dem == 2)
		return 1;
	return 0;
}

int NguyenToDau(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktNguyenTo(a[i][j]) == 1)
				return a[i][j];
	return -1;
}

int NguyenToLonNhat(int a[][500], int m, int n)
{
	int lc = NguyenToDau(a,m,n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktNguyenTo(a[i][j] == 1))
				if (a[i][j] > lc)
					lc = a[i][j];
	return lc;
}
