#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

void Nhap(int[][100], int&, int&);
void Xuat(int[][100], int, int);
int KiemTra(int[][100], int, int);


int main()
{
    int a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int kq = KiemTra(a, m, n);
    if (kq == 1)
        cout << "giam dan";
    else
        cout << "khong phai";

    return 0;
}

void Nhap(int a[][100], int& m, int& n)
{
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}

void Xuat(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(8) << a[i][j];
        }
        cout << "\n";
    }
}

int KiemTra(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
            if (a[i][j] < a[i][j + 1])
                return 0;
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m - 1; i++)
            if (a[i][j] < a[i + 1][j])
                return 0;
    }
    return 1;
}
