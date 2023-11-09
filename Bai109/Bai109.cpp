#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
int ktDong(float[][500], int, int, int);
void LietKe(float[][500], int, int);

int main()
{
	float b[500][500];
	int k, l, n;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Cac dong co chua gia tri am la: ";
	LietKe(b, k, l);
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

int ktDong(float a[][500], int m, int n, int d)
{
	int flag = 0;
	for (int j = 0; j < n; j++)
			if (a[d][j] < 0)
				flag = 1;
	return flag;
}

void LietKe(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i) == 1)
			cout << i << " ";
}