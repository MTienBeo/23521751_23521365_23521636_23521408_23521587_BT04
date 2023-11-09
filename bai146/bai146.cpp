#include<stdio.h>
#include<conio.h>
#include<math.h>

int nto(int n)
{
	int i;
	if (n < 2) return 0;
	for (i = 2;i <= sqrt(n);i++)
		if (n % i == 0) return 0;
	return 1;
}

main()
{
	int n, m, i, j, a[20][20];
	scanf("%d%d", &n, &m);
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			scanf("%d", &a[i][j]);

	int k = m;
	for (j = 0;j < k;j++)
	{
		for (i = 0;i < n;i++)
		{
			if (nto(a[i][j]))
			{
				for (i = 0;i < n;i++)
				{
					a[i][j] = a[i][j + 1];
				}

				m--;
			}

		}

	}

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}