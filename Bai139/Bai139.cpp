#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void DuongBienTang(float[][100], int, int);
void SapXepHinhXoanTron(float[][100], int, int);
void HoanVi(float&, float&);

int main()
{
    float b[100][100];
    int k, l;
    Nhap(b, k, l);
    cout << "Ma tran mxn: " << endl;
    Xuat(b, k, l);
    cout << "Mang sau khi sap xep la: " << endl;
    SapXepHinhXoanTron(b, k, l);
    Xuat(b, k, l);
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
            cout << fixed << setw(10) << setprecision(3) << a[i][j];
        cout << endl;
    }
}

void DuongBienTang(float a[][100], int m, int n)
{
    float b[100]{};
    int k;
    int i, j;

    k = 0;
    for (j = 0; j <= n - 2; j++)
        b[k++] = a[0][j];
    for (i = 0; i <= m - 2; i++)
        b[k++] = a[i][n - 1];
    for (j = n - 1; j >= 1; j--)
        b[k++] = a[m - 1][j];
    for (i = m - 1; i >= 1; i--)
        b[k++] = a[i][0];

    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            if (b[i] > b[j] && b[i] > 0 && b[j] > 0)
                HoanVi(b[i], b[j]);

    k = 0;
    for (j = 0; j <= n - 2; j++)
        a[0][j] = b[k++];
    for (i = 0; i <= m - 2; i++)
        a[i][n - 1] = b[k++];
    for (j = n - 1; j >= 1; j--)
        a[m - 1][j] = b[k++];
    for (i = m - 1; i >= 1; i--)
        a[i][0] = b[k++];
}

void SapXepHinhXoanTron(float a[][100], int m, int n)
{
    DuongBienTang(a, m, n);

    float b[100 * 100]{};
    int k = 0;
    int i, j;

    for (int v = 0; v < m / 2 && v < n / 2; v++) {
        for (i = v; i < m - v; i++) {
            b[k++] = a[i][v];
        }
        for (j = v + 1; j < n - v; j++) {
            b[k++] = a[m - v - 1][j];
        }
        if (v != m - v - 1) {
            for (i = m - v - 2; i >= v; i--) {
                b[k++] = a[i][n - v - 1];
            }
        }
        if (v != n - v - 1) {
            for (j = n - v - 2; j > v; j--) {
                b[k++] = a[v][j];
            }
        }
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (b[i] > b[j]) {
                HoanVi(b[i], b[j]);
            }
        }
    }

    k = 0;
    for (int v = 0; v < m / 2 && v < n / 2; v++) {
        for (i = v; i < m - v; i++) {
            a[i][v] = b[k++];
        }
        for (j = v + 1; j < n - v; j++) {
            a[m - v - 1][j] = b[k++];
        }
        if (v != m - v - 1) {
            for (i = m - v - 2; i >= v; i--) {
                a[i][n - v - 1] = b[k++];
            }
        }
        if (v != n - v - 1) {
            for (j = n - v - 2; j > v; j--) {
                a[v][j] = b[k++];
            }
        }
    }
}

void HoanVi(float& x, float& y) {
    float temp = x;
    x = y;
    y = temp;
}
