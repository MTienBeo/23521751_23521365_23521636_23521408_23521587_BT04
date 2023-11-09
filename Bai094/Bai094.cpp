#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
int ktSoHoanThien(int);
int DemDong(int[][500], int, int, int);
int DemLonNhat(int[][500], int, int);
void LietKe(int[][500], int, int);

int main()
{
	int b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Dong co nhieu so hoan thien nhat la: ";
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

int ktSoHoanThien(int n)
{
	if(n <= 1) 
		return 0;
	int s = 1; 
	int i = 2;
	while (i <= n / 2)
	{
		if (n % i == 0)
			s += i;
		i++;
	}
	if (s == n)
		return 1;
	return 0;
}

int DemDong(int a[][500], int m, int n, int d)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
		if (ktSoHoanThien(a[d][j]) == 1)
			dem++;
	return dem;
}

int DemLonNhat(int a[][500], int m, int n)
{
	int lc = DemDong(a, m, n, 0);
	for (int i = 0; i < m; i++)
		if (DemDong(a, m, n, i) > lc)
			lc = DemDong(a, m, n, i);
	return lc;
}

void LietKe(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++) 
		if (DemDong(a, m, n, i) == DemLonNhat(a, m, n)) 
			cout << i << " ";
}