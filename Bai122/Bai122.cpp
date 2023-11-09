#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void HoanVi(float&, float&);
void XepTangDong(float[][100], int, int, int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int d;
    cout << "nhap dong can sap xep: ";
    cin >> d;
    cout << "dong sau khi sap xep la: ";
    XepTangDong(a, m, n, d);
    for (int j = 0; j < n; j++)
        cout << setw(8) << a[d][j];
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

void HoanVi(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void XepTangDong(float a[][100] , int m, int n, int d)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n-1; j++)
            if (a[d][i] > a[d][j])
                HoanVi(a[d][i], a[d][j]);
    }
}