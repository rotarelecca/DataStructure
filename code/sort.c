#include "algorithm.h"

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void ShowList(int *num, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(num + i));
	}
	printf("\n");
}

void BubbleSort(int *num, int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j >= i + 1; j--)
		{
			if (*(num + j) < *(num + i))
			{
				swap(num + j, num + i);
			}
		}
	}
}