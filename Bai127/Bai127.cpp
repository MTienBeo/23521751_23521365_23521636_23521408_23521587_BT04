#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void HoanVi(float&, float&);
void CotTangDan(float[][100], int, int, int);
void CotGiamDan(float[][100], int, int, int);
void SapXep(float[][100], int, int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    SapXep(a, m, n);
    cout << "ma tran khi sap xep la: " << endl;
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

void HoanVi(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}

void CotTangDan(float a[][100], int m, int n, int c)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
            if (a[i][c] > a[j][c])
                HoanVi(a[i][c], a[j][c]);
    }
}
void CotGiamDan(float a[][100], int m, int n, int c)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
            if (a[i][c] < a[j][c])
                HoanVi(a[i][c], a[j][c]);
    }
}

void SapXep(float a[][100], int m, int n)
{
    for (int j = 0; j < m; j++)
    {
        if (j % 2 == 0)
            CotGiamDan(a, m, n, j);
        else
            CotTangDan(a, m, n, j);
    }
}