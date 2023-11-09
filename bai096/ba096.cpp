#include<conio.h>
#include<stdio.h>
int main() {
	int mang[30];
	int n;
	int max = 0;
	int max2 = 0;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	for (;n <= 0;)
	{
		printf("n phai > 0 \n");
		printf("Nhap lai n:");
		scanf("%d", &n);
	}
	// Kiem tra dieu kien cua n
	printf("Nhap gia tri cua mang:\n");
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]: ", i);
		scanf("%d", &mang[i]);
	}
	// Nhap gia tri cua mang

	for (int i = 0; i < n; i++) {
		if (max < mang[i])
		{
			max = mang[i];
		}
	}
	// Gan gia tri lon nhat cua mang cho max
	for (int i = 0; i < n; i++) {
		if (max == mang[i])
		{
			continue;
		}
		else if (max2 < mang[i]) {
			max2 = mang[i];
		}
	}
	// Gan gia tri lon hai cua mang cho max2
	printf("Output:%d", max2);
	return 0;
}