#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,temp;
	scanf("%d", &n);

	int* p = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j<n - 1-i; j++)
		{
			if (p[j] > p[j + 1])
			{
				temp = p[j+1];
				p[j + 1] = p[j];
				p[j] = temp;
			}
		}
	}

	printf("%d", p[n-1]-p[0]);
	free(p);
}