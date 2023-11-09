#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void XayDung(float[][100], int, int, float[][100], int&, int&);
int DemLanCan(float[][100], int, int, int, int);

int main()
{
    float b[100][100];
    int k, l;
    Nhap(b, k, l);
    cout << "Ma tran " << k << "x" << l << ": " << endl;
    Xuat(b, k, l);

    float a[100][100];
    int d, c;
    XayDung(b, k, l, a, d, c);
    cout << "Ma tran ket qua la: " << endl;
    Xuat(a, d, c);

    cout << endl;
    cout << "Ket thuc!!!\n\n\n";
    return 0;
}

void Nhap(float a[][100], int& m, int& n)
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

void Xuat(float a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(10) << setprecision(3) << a[i][j];
        cout << endl;
    }
}

void XayDung(float a[][100], int m, int n, float b[][100], int& k, int& l)
{
    k = m;
    l = n;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < l; j++)
            b[i][j] = DemLanCan(a, m, n, i, j);
}

int DemLanCan(float a[][100], int m, int n, int d, int c)
{
    int dem = 0;
    for (int di = -1; di <= 1; di++)
        for (int dj = -1; dj <= 1; dj++)
            if (d + di >= 0 && d + di < m && c + dj >= 0 && c + dj < n && !(di == 0 && dj == 0) && a[d + di][c + dj] > 0)
                dem++;
    return dem;
}
