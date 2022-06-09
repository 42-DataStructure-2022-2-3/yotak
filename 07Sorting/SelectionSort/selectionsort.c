#include "selectionsort.h"

int		*makeArray(int maxElementCount)
{
	int	*arr;

	arr = (int *)calloc(maxElementCount, sizeof(int));
	return (arr);
}

void	swap(int **arr, int idx1, int idx2)
{
	int	tmp;
	tmp = *arr[idx1];
	*arr[idx1] = *arr[idx2];
	*arr[idx2] = tmp;
}

void	printArray(int *arr, int maxElementCount)
{
	for (int i = 0; i < maxElementCount; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

void	selectionSort(int *arr)
{
	int	minIdx;
	int maxElementCount;

	maxElementCount = 8;
	for (int i = 0; i < maxElementCount - 1; i++)
	{
		minIdx = i;
		for (int j = i + 1; j < maxElementCount; j++)
		{
			if (arr[i] < arr[j])
				minIdx = j;
		}
		swap(&arr, i, minIdx);
	}
	printArray(arr, maxElementCount);
}

int	main()
{
	int	*arr = makeArray(8);
	
}