#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void XoaCot(float[][100], int, int&, int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int c;
    cout << "Nhap cot can xoa: ";
    cin >> c;
    cout << "Ma tran sau khi xoa cot la: " << endl;
    XoaCot(a, m, n, c);
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

void XoaCot(float a[][100], int m, int& n, int c)
{
    if (c < 0 || c >= n)
    {
        cout << "Khong co cot ";
        return;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = c; j < n - 1; j++)
            a[i][j] = a[i][j + 1];
    }
    n--;
    for (int i = 0; i < m; i++)
    {
        a[i][n] = 0;
    }
}