#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktToanDuong(float[][100], int, int, int);
void ThemDong(float[][100], int&, int,int);
void Them(float[][100], int&, int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    Them(a, m, n);
    cout << "Ma tran sau khi sap xep la: " << endl;
    Xuat(a, m, n);
}

void Nhap(float a[][100], int& m, int& n)
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

void Xuat(float a[][100], int m, int n)
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

int ktToanDuong(float a[][100], int m, int n, int d)
{
    int flag = 1;
    for (int j = 0; j < n; j++)
    {
        if (a[d][j] < 0)
            flag = 0;
    }
    return flag;
}
void ThemDong(float a[][100], int& m, int n,int d)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = m; i >= d + 1; i--)
            a[i][j] = a[i - 1][j];
        a[d][j] = 1;
    }
    m++;
}
void Them(float a[][100], int& m, int n)
{
    for (int i = m - 1; i >= 0; i--)
    {
        if (ktToanDuong(a, m, n, i))
            ThemDong(a, m, n, (i + 1));
    }
}

