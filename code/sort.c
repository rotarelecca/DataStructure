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

void MergePass(int *num1, int *num2, int n, int h)
{
	int i = 0, t = 0;
	for (i = 0; i + 2 * h - 1 < n; i += 2 * h)
	{
		Merge(num1, num2, i, i + h - 1, i + 2 * h -1);
	}
	if (i + h - 1 < n)
	{
		Merge(num1, num2, i, i + h - 1, n - 1);
	}
	else
	{
		for (t = i; t < n; t++)
		{
			*(num2 + t) = *(num1 + t);
		}
	}
}

void MergeSort(int *num, int n)
{
	int h = 1;
	int i = 0;
	int *num2 = NULL;
	num2 = (int *)malloc(n * sizeof(int));
	if (num2 == NULL)
	{
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		*(num2 + i) = 0;
	}
	while (h < n)
	{
		MergePass(num, num2, n, h);
		h *= 2;
		MergePass(num2, num, n, h);
		h *= 2;
	}
	free(num2);
	num2 = NULL;
}
