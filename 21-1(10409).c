#include <stdio.h>

int main()
{
	int n, t, sum=0,count=0;
	int a[100] = { 0, };

	scanf("%d %d", &n, &t);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int j = 0; j < n; j++)
	{
		sum+=a[j];

		if (sum > t)
			break;
		else
			count+=1;
	}
	printf("%d", count);

}