#include<stdio.h>

#include<conio.h>

#include<math.h>

#define MAX 100

void NhapMang(int a[][MAX], int& dong, int& cot)

{

	//Nh?p s? d�ng

	do

	{

		printf("\nNhap vao so dong: ");

		// C�ch t� ??o: scanf("dong =%d",&dong);  // L�c nh?p ph?i vi?t th�m  ch? ( dong =  ) ? khung console

		scanf("%d", &dong);



		if (dong < 1 || dong > MAX)

		{

			printf("\nSo dong khong hop le. Xin kiem tra lai!");

		}



	} while (dong < 1 || dong > MAX);



	//Nh?p s? c?t

	do

	{

		printf("\nNhap vao so cot: ");

		scanf("%d", &cot);



		if (cot < 1 || cot > MAX)

		{

			printf("\nSo cot khong hop le. Xin kiem tra lai!");



		}



	} while (cot < 1 || cot > MAX);

	for (int i = 0; i < dong; i++)

	{

		for (int j = 0; j < cot; j++)

		{

			printf("\nNhap a[%d][%d] = ", i, j);

			scanf("%d", &a[i][j]);

		}

	}

}



void XuatMang(int a[][MAX], int dong, int cot)

{

	for (int i = 0; i < dong; i++)

	{

		for (int j = 0; j < cot; j++)

		{

			printf("%4d", a[i][j]);

		}

		printf("\n\n");

	}

}



int KiemTraNguyenTo(int n)

{

	if (n < 2)

	{

		return 0;

	}

	else if (n > 2)

	{

		if (n % 2 == 0)

		{

			return 0;

		}

		for (int i = 3; i <= sqrt((float)n); i += 2)

		{

			if (n % i == 0)

			{

				return 0;

			}

		}

	}

	return 1;

}



int TimSoNguyenToDau(int a[][MAX], int dong, int cot)

{

	for (int i = 0; i < dong; i++)

	{

		for (int j = 0; j < cot; j++)

		{

			if (KiemTraNguyenTo(a[i][j]) == 1)

			{

				return a[i][j];

			}

		}

	}

	return -1;

}

int main()

{

	int a[MAX][MAX], dong, cot;

	NhapMang(a, dong, cot);

	XuatMang(a, dong, cot);

	int NguyenToDau = TimSoNguyenToDau(a, dong, cot);

	printf("\nSo nguyen to dau tien trong ma tran = %d", NguyenToDau);



	getch();

	return 0;

}