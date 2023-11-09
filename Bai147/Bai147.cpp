#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void ThemDong(float[][100], int&, int, int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int d;
    cout << "Nhap vi tri dong can chen: ";
    cin >> d;
    cout << "Ma tran sau khi chen la: " << endl;
    ThemDong(a, m, n, d);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(8) << a[i][j];
        }
        cout << "\n";
    }
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

void ThemDong(float a[][100], int& m, int n, int d)
{
    if (d < 0 || d >= m)
    {
        cout << "Khong co dong";
        return;
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = m; i > d; i--)
            a[i][j] = a[i - 1][j];
    }
    for (int j = 0; j < n; j++)
    {
        a[d][j] = 1;
    }
    m++;
}