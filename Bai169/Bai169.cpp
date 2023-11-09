#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void NhapB(float[][100], int&, int&);
void NhapA(float[][100], int&, int&);
void Xuat(float[][100], int, int);
int ktCon(float[][100], int, int, float[][100], int, int);

int main()
{
    float b[100][100];
    int k, l;
    NhapB(b, k, l);
    cout << "Ma tran B " << k << "x" << l << ": " << endl;
    Xuat(b, k, l);

    float a[100][100];
    int d, c;
    NhapA(a, d, c);
    cout << "Ma tran A " << d << "x" << c << ": " << endl;
    Xuat(a, d, c);

    if (ktCon(a, d, c, b, k, l) == 1)
        cout << "Ma tran A la con cua ma tran B." << endl;
    else
        cout << "Ma tran A khong la con cua ma tran B." << endl;

    cout << endl;
    cout << "Ket thuc!!!\n\n\n";
    return 0;
}

void NhapB(float a[][100], int& m, int& n)
{
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
        }
}

void NhapA(float a[][100], int& d, int& c)
{
    cout << "Nhap d: ";
    cin >> d;
    cout << "Nhap c: ";
    cin >> c;
    srand(time(NULL));
    for (int i = 0; i < d; i++)
        for (int j = 0; j < c; j++)
        {
            a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
        }
}

void Xuat(float a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout  << setw(10) << setprecision(3) << a[i][j];
        cout << endl;
    }
}

int ktCon(float a[][100], int m, int n, float b[][100], int k, int l)
{
    if (m > k || n > l)
        return 0;
    int flag = 0;
    for (int d = 0; d <= k - m; d++)
        for (int c = 0; c <= l - n; c++)
        {
            int co = 1;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (a[i][j] != b[d + i][c + j])
                        co = 0;
            if (co == 1)
                flag = 1;
        }
    return flag;
}
