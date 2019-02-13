#ifndef __algorithm_h
#define __algorithm_h

#include <stdio.h>

void swap(int *, int *);
void BubbleSort(int *, int);
void SelectSort(int *, int);
void InsertSort(int *, int);

int FindPivot(int *, int, int);
int Partition(int *, int, int, int);
void QuickSort(int *, int i, int j);

void Merge(int *, int *, int, int, int);
void ShowList(int *, int);
#endif
