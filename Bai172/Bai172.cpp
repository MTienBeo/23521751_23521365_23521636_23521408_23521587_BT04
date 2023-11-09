#include <iostream>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void TimConTongLonNhat(float[][100], int, int, int&, int&, int&, int&);

int main()
{
    float a[100][100];
    int m, n;
    Nhap(a, m, n);
    Xuat(a, m, n);

    int q, w, e, r;
    TimConTongLonNhat(a, m, n, q, w, e, r);

    if (q != -1 && w != -1 && e != -1 && r != -1)
    {
        cout << "Ma tran con co tong lon nhat la:" << endl;
        for (int i = q; i <= e; i++)
        {
            for (int j = w; j <= r; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "Khong ton tai ma tran con." << endl;
    }

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
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
    }
}

void Xuat(float a[][100], int m, int n)
{
    cout << "Ma tran vua nhap la:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void TimConTongLonNhat(float a[][100], int m, int n, int& q, int& w, int& e, int& r)
{
    float TongMax = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = i; k < m; k++)
            {
                for (int l = j; l < n; l++)
                {
                    float sum = 0;
                    for (int x = i; x <= k; x++)
                    {
                        for (int y = j; y <= l; y++)
                            sum += a[x][y];
                    }
                    if (sum > TongMax)
                    {
                        TongMax = sum;
                        q = i;
                        w = j;
                        e = k;
                        r = l;
                    }
                }
            }
        }
    }
}