#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void HoanVi(float&, float&);
void DuongGiam(float[][100], int, int);
void AmTang(float[][100], int, int);
void SapXep(float[][100], int, int);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);
    AmTang(a, m, n);
    DuongGiam(a, m, n);
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

void DuongGiam(float a[][100], int m, int n)
{
    float b[500];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            if (a[i][j] > 0)
                b[k++] = a[i][j];
    }

    for (i = 0; i <= k - 2; i++)
    {
        for (j = i + 1; j <= k - 1; j++)
            HoanVi(b[i], b[j]);

        k = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (a[i][j] > 0)
                    a[i][j] = b[k++];
    }

}

void AmTang(float a[][100], int m, int n)
{

    float b[500];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            if (a[i][j] < 0)
                b[k++] = a[i][j];
    }

    for (i = 0; i <= k - 2; i++)
    {
        for (j = i + 1; j <= k - 1; j++)
            if (b[i] > b[j])
                HoanVi(b[i], b[j]);
    }

    k = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            if (a[i][j] < 0)
                a[i][j] = b[k++];
    }
}

void SapXep(float a[][100], int m, int n)
{
    AmTang(a, m, n);
    DuongGiam(a, m, n);
}
