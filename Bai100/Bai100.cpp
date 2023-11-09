#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
int ViTriDuongDau(int[], int);
int ViTriDuongNhoNhat(int[], int);
int TimChuSo(int**, int, int);

int main()
{
	int** a;
	int m, n;
	cout << "\nNhap ma tran: ";
	Nhap(a, m, n);
	cout << "\nMa Tran: " << endl;
	Xuat(a, m, n);

    cout << "\nChu so xuat hien it nhat : " << TimChuSo(a, m, n);

	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
	return 0;
}

void Nhap(int**& a, int& m, int& n)
{
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}

void Xuat(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setprecision(2) << setw(10) << a[i][j];
		cout << endl;
	}
}

int ViTriDuongDau(int a[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i] > 0)
            return i;
    }
    return -1;
}

int ViTriDuongNhoNhat(int a[], int n)
{
    int lc = ViTriDuongDau(a, n);
    if (lc == -1)
        return -1;
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i] > 0 && a[i] < a[lc])
            lc = i;
    }
    return lc;
}

int TimChuSo(int **a, int m, int n)
{
    int dem[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                dem[0]++;
            int t = abs(a[i][j]);
            while (t != 0)
            {
                int dv = t % 10;
                dem[dv]++;
                t = t / 10;
            }
        }
    }
    return ViTriDuongNhoNhat(dem, 10);
}