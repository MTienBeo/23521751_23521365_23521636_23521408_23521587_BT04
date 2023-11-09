#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
float Tong(float**, int, int);
bool ktCucDai(float**, int, int, int, int);

int main()
{
    float** a;
    int m, n;
    cout << "\nNhap ma tran: ";
    Nhap(a, m, n);
    cout << "\nMa Tran: " << endl;
    Xuat(a, m, n);

    cout << "\nTong cac gia tri cuc dai bang " << setprecision(2) << fixed << Tong(a, m, n);

    for (int i = 0; i < m; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Nhap(float**& a, int& m, int& n)
{
    cout << "\nNhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    a = new float* [m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new float[n];
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
}

void Xuat(float** a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << fixed << setprecision(2) << setw(10) << a[i][j];
        cout << endl;
    }
}

float Tong(float** a, int m, int n)
{
    float S = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (ktCucDai(a, m, n, i, j))
                S += a[i][j];
    return S;
}

bool ktCucDai(float** a, int m, int n, int i, int j)
{
    int vtd[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
    int vtc[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
    for (int k = 0; k < 8; k++)
    {
        int di = i + vtd[k];
        int dj = j + vtc[k];
        if (di >= 0 && di < m && dj >= 0 && dj < n)
        {
            if (a[i][j] < a[di][dj])
                return false;
        }
    }
    return true;
}