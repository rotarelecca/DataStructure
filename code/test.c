#include "algorithm.h"

int main()
{
	int num[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
	ShowList(num, 10);
	QuickSort(num, 0, 9);
	ShowList(num, 10);
	return 0;
}
