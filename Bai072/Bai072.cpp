#include <iostream>
using namespace std;

bool DaXuatHien(float[], int, float);
int DemPhanBiet(float[], int);
int DemPhanBiet(float[][500], int, int);

int main()
{
    int m, n;
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    float a[500][500];
    cout << "Nhap cac phan tu cua ma tran:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int soGiaTriPhanBiet = DemPhanBiet(a, m, n);
    cout << "So luong gia tri phan biet: " << soGiaTriPhanBiet << endl;

    return 0;
}

bool DaXuatHien(float a[], int n, float giaTri)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == giaTri)
        {
            return true;
        }
    }
    return false;
}

int DemPhanBiet(float a[], int n)
{
    int dem = 0;
    float giaTriPhanBiet[500];
    for (int i = 0; i <n; i++)
    {
        if (!DaXuatHien(giaTriPhanBiet, dem, a[i]))
        {
            giaTriPhanBiet[dem] = a[i];
            dem++;
        }
    }
    return dem;
}

int DemPhanBiet(float a[][500], int m, int n)
{
    int dem = 0;
    float giaTriPhanBiet[500];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!DaXuatHien(giaTriPhanBiet, dem, a[i][j]))
            {
                giaTriPhanBiet[dem] = a[i][j];
                dem++;
            }
        }
    }
    return dem;
}