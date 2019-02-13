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

void SelectSort(int *num, int n)
{
	int i = 0, j = 0;
	int min = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (*(num + j) < *(num + min))
			{
				min = j;
			}
		}
		swap(num + i, num + min);
	}
}

void InsertSort(int *num, int n)
{
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++)
	{
		j = i;
		while (*(num + j + 1) < *(num + j))
		{
			swap(num + j + 1, num + j);
			j--;
		}
	}
}

int FindPivot(int *num, int i, int j)
{
	int a = *(num + i);
	int k = 0;
	for (k = i + 1; k <= j; k++)
	{
		if (*(num + k) > a)
		{
			return k;
		}
		else if (*(num + k) < a)
		{
			return i;
		}
	}
	return -1;
}

int Partition(int *num, int i, int j, int k)
{
	int l = i, r = j;
	do {
		for (; *(num + l) < k; l++)
		{
			;
		}
		for (; *(num + r) >= k; r--)
		{
			;
		}
		if (l < r)
		{
			swap(num + l, num + r);
		}
	} while (l < r);
	return l;
}

void QuickSort(int *num, int i, int j)
{
	int key = 0;
	int k = 0;
	int pivotindex = 0;
	pivotindex = FindPivot(num, i, j);
	if (pivotindex != -1)
	{
		key = *(num + pivotindex);
		k = Partition(num, i, j, key);
		QuickSort(num, i, k - 1);
		QuickSort(num, k, j);
	}
}

void Merge(int *num1, int *num2, int s, int m, int t)
{
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		*(num2 + k++) = (*(num1 + i) <= *(num1 + j)) ? *(num1 + i++) : *(num1 + j++);
	}
	while (i <= m)
	{
		*(num2 + k++) = *(num1 + i++);
	}
	while (j <= t)
	{
		*(num2 + k++) = *(num1 + j++);
	}
}
