#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float TimMax(float[][100], int, int,int);

int main()
{
    float a[100][100];
    int m, n;
    int d;
    Nhap(a, m, n);
    Xuat(a, m, n);
    cout << "Nhap dong can tinh: ";
    cin >> d;
    cout << "gia tri lon nhat cua dong la: " << TimMax(a, m, n,d);
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

float TimMax(float a[][100], int m, int n,int d)
{
    if (d<0 && d>n - 1)
        cout << "khong co";
    int lc = a[d][0];
        for (int j = 0; j < n; j++)
        {
            if (a[d][j] > lc)
                lc = a[d][j];
        }
    return lc;
}