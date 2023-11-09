#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void XayDung(float[][100], int, int, float[][100], int&, int&);

int main()
{
    float a[100][100];
    float b[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    int k,l;
    XayDung(a, m, n, b, k, l);
    cout << "Ma tran sau khi sap xep la: " << endl;
    Xuat(b,k,l);
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

void XayDung(float a[][100], int m, int n, float b[][100], int& k, int& l)
{
    k = m;
    l = n;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
            b[i][j] = abs(a[i][j]);
    }
}