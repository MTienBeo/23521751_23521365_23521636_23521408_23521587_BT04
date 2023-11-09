#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void Xoay90(float[][100], int&, int&);
void Xoay180(float[][100], int&, int&);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    Xoay180(a, m, n);
    cout << "Ma tran sau khi sap xep la: " << endl;
    Xuat(a, m, n);
    return 0;
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

void Xoay90(float a[][100], int& m, int& n)
{
    float b[100][100];
    int k, l;
    k = m;
    l = n;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
            b[i][j] = a[j][n - 1 - i];
    }
    m = k;
    n = l;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = b[i][j];
    }
}
void Xoay180(float a[][100], int& m, int& n)
{
    Xoay90(a, m, n);
    Xoay90(a, m, n);

}