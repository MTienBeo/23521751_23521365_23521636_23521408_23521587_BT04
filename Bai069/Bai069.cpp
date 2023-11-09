#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
int ktCucTieu(float[][500], int, int, int, int);
int DemCucTieu(float[][500], int, int);

int main()
{
	float b[500][500];
	int k, l;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "So cuc tieu trong ma tran la:" ;
	cout << DemCucTieu(b, k, l);
	cout << endl;
	cout << "Ket thuc!!!\n\n\n";
	return 0;
}

void Nhap(float a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
		}
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(10) << setprecision(3) << a[i][j];
		cout << endl;
	}
}

int ktCucTieu(float a[][500], int m, int n, int d, int c)
{
	int flag = 1;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
			if (d + dj >= 0 && d + di < m &&
				c + dj >= 0 && c + dj < n &&
				!(di == 0 && dj == 0) &&
				a[d + di][c + dj] < a[d][c])
				flag = 0;
	return flag;
}

int DemCucTieu(float a[][500], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucTieu(a, m, n ,i, j) == 1)
				dem++;
	return dem;
}