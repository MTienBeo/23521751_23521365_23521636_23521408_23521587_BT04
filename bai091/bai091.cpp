#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define MAX 100

void nhapmatran(int a[MAX][MAX], int& m, int& n)
{
	do {
		printf("Nhap vao so dong cua ma tran:m=");
		scanf("%d", &m);
		if (m<1 || m>MAX)
			printf("So dong ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	} while (m<1 || m>MAX);
	do {
		printf("Nhap vao so cot cua ma tran:n=");
		scanf("%d", &n);
		if (n<1 || n>MAX)
			printf("So cot ban nhap vao khong hop le!Xin vui long nhap lai!\n");
		else
			break;
	} while (n<1 || n>MAX);
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			printf("Nhap vao a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void xuatmatran(int a[MAX][MAX], int m, int n)
{
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

void tinhtongcaccotvalietkecotcotongnhonhat(int a[MAX][MAX], int m, int n)
{
	int b[MAX], min = INT_MAX, vitri = 0;
	for (int j = 0;j < n;j++)
	{
		int tong = 0;
		for (int i = 0;i < m;i++)
		{
			tong += a[i][j];
			b[j] = tong;
		}
	}
	for (int j = 0;j < n;j++)
		printf("\nTong cac phan tu cua cot %d la:%d", j, b[j]);
	for (int j = 0;j < n;j++)
	{
		if (b[j] < min)
		{
			min = b[j];
		}
	}
	printf("\nCac cot co tong nho nhat la:");
	for (int j = 0;j < n;j++)
	{
		if (b[j] == min)
		{
			vitri = j;
			printf("%4d", vitri);
		}
	}
}

void main()
{
	int a[MAX][MAX], m, n, tieptuc;
quaylai:nhapmatran(a, m, n);
	printf("\n>>>>>>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a, m, n);
	tinhtongcaccotvalietkecotcotongnhonhat(a, m, n);
	printf("\nBan co muon tiep tuc chay chuong trinh hay khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc = getch();
	if (tieptuc == 'c' || tieptuc == 'C')
		goto quaylai;
}