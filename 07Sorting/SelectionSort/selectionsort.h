#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <stdlib.h>
#include <stdio.h>

int		*makeArray(int maxElementCount);
void	printArray(int *arr, int maxElementCount);
void	swap(int **arr, int idx1, int idx2);
void	selectionSort(int *arr);
#endif