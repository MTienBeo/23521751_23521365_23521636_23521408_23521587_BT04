#include <iostream>
#include <time.h>
#define MAX 100
using namespace std;

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu thu " << i << ": ";
		cin >> a[i];
	}
}

void MangNgauNhien(int a[], int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10 - rand() % 10;
}

void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

int TongPTCucTieu(int a[], int n)
{
	int i, tong = 0;
	if (a[0] < a[1])
		tong = tong + a[0];
	if (a[n - 1] < a[n - 2])
		tong = tong + a[n - 1];
	for (i = 0; i < n; i++)
	{
		if (a[i - 1] > a[i] && a[i] < a[i + 1])
			tong = tong + a[i];
	}
	return tong;
	return -1;
}

void main()
{
	int a[MAX], i, n, kq;

	cout << "Nhap so luong phan tu thuc: "; cin >> n;

	//NhapMang(a,n);

	MangNgauNhien(a, n);

	XuatMang(a, n);

	kq = TongPTCucTieu103(a, n);
	cout << "\nTong cac phan tu cuc tieu co trong mang la: " << kq;

	cout << endl;
}
