#include "floyd.h"

void displayMatrix(LinkedGraph *lg, int **arr)
{
	for (int i = 0; i < lg->maxVertexCount; i++)
	{
		printf("=============================\n");
		for (int j = 0; j < lg->maxVertexCount; j++)
			printf("%d", arr[i][j]);
		printf("\n");
	}
}

void	floyd(LinkedGraph *lg)
{
	int	**arr;

	arr = createWeightMatrix(lg);
	
	for (int i = 0; i < lg->maxVertexCount; i++)
	{
		for (int j = 0; j < lg->maxVertexCount; j++)
			for (int k = 0; k < lg->maxVertexCount; k++)
				if (arr[j][i] + arr[i][k] < arr[j][k])
					arr[j][k] = arr[j][i] + arr[i][k];
		displayMatrix(lg, arr);
	}
}

int main()
{
	int size = 6;
	LinkedGraph *lg = createLinkedGraph(size);

	for (int i = 0 ; i < size; i++)
		addVertexLG(lg, i);
	addEdgeWithWeightLG(lg, 1, 0, 4);
	addEdgeWithWeightLG(lg, 1, 2, 2);
	addEdgeWithWeightLG(lg, 0, 2, 3);
	addEdgeWithWeightLG(lg, 2, 3, 1);
	addEdgeWithWeightLG(lg, 3, 4, 1);
	addEdgeWithWeightLG(lg, 3, 5, 5);
	addEdgeWithWeightLG(lg, 4, 5, 6);

	displayLinkedGraph(lg);
	floyd(lg);
	return 0;
}