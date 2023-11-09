#include<stdio.h>
#include<conio.h>
#define MAX 100

void nhapmatran(float a[MAX][MAX], int& n, int& m)
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
			scanf("%f", &a[i][j]);
		}
	}
}

void xuatmatran(float a[MAX][MAX], int n, int m)
{
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			printf("%16f", a[i][j]);
		}
		printf("\n");
	}
}

void lietkecottang(float a[MAX][MAX], int n, int m)
{
	int b[MAX];	// m?ng b ph?i ?? giá tr? nguyên vì nó có tác d?ng ?? l?u các giá tr? dem vào.
	for (int j = 0;j < n;j++)
	{
		int dem = 0;
		for (int i = 1;i < m;i++)
		{
			float c = a[i][j] - a[i - 1][j];
			if (c >= 0)
			{
				dem++;
				b[j] = dem;
			}
		}
	}
	for (int j = 0;j < n;j++)
	{
		if (b[j] == m - 1)
			printf("\nCot: %d", j);
	}
}

void main()
{
	float a[MAX][MAX];
	int n, m, tieptuc;
quaylai:nhapmatran(a, n, m);
	printf("\n>>>>>>>>>>>>>>>MA TRAN VUA NHAP LA:<<<<<<<<<<<<<<<<<<<<<\n");
	xuatmatran(a, n, m);
	printf("\n>>>>>>>>>>>>>>>>CAC COT TRONG MA TRAN TANG DAN LA:<<<<<<<<<<<<<<<<<<<<\n");
	lietkecottang(a, n, m);
	printf("\nBan co muon tiep tuc chay chuong trinh khong ? Neu co bam phim C,nguoc lai bam bat ky 1 phim nao khac de ket thuc\n");
	tieptuc = getch();
	if (tieptuc == 'c' || tieptuc == 'C')
		goto quaylai;
}