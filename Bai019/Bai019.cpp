#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
int ktDoiXung(int);
void LietKe(int[][500], int, int, int);

int main()
{
	int b[500][500];
	int k, l, n;
	Nhap(b, k, l);
	cout << "Ma tran mxn: " << endl;
	Xuat(b, k, l);
	cout << "Nhap cot c: ";
	cin >> n;
	cout << "Liet ke so doi xung tren cot " << n << " :";
	LietKe(b, k, l, n);
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

int ktDoiXung(int n)
{
	int dn = 0;
	int t = n;
	while (t != 0 )
	{
		int dv = t % 10;
		dn = dn * 10 + dv;
		t = t / 10;
	}
	if (dn == n)
		return 1;
	else
		return 0;
}

void LietKe(int a[][500], int m, int n, int c)
{
		for (int i = 0; i < m; i++)
				if (ktDoiXung(a[i][c]) == 1)
			cout << setw(8) << a[i][c];
}