#include "dijkstra.h"

// 가중치가 0이면 자기 자신
int	*createArray(int maxVertexCount)
{
	int	*arr;

	arr = calloc(maxVertexCount, sizeof(int));
	return (arr);
}

int	**createWeightMatrix(LinkedGraph *lg)
{
	int maxVertices = lg->maxVertexCount;
	int	matrix[maxVertices][maxVertices];
	int	n;
	
	for (int i = 0; i < maxVertices; i++)
		for (int j = 0; j < maxVertices; j++)
			matrix[i][j] = -1;
	initWeightMatrix(lg, matrix);
	return (matrix);
}

void	initWeightMatrix(LinkedGraph *lg, int **matrix)
{
	LinkedList	*pList;
	ListNode	*node;

	//사용되지 않는 노드 : -1로 초기화
	//사용되는 노드 && 경로가 없으면 MAX_INT
	for (int i = 0; i < lg->maxVertexCount; i++)
	{
		if (lg->pVertex[i] == USED)
		{
			pList = lg->ppAdjEdge[i]->headerNode.pLink;
			node = pList->headerNode.pLink;
			for (int j = 0; j < lg->maxVertexCount; j++)
			{
				if (node && node->data.vertexID == j)
				{
					matrix[i][j] = node->data.weight; 
					if (node->pLink)
						node = node->pLink;
				}
				else
					matrix[i][j] = INT32_MAX;
			}
		}
		else
			for (int j = 0; j < lg->maxVertexCount; j++)
				matrix[i][j] = -1;
	}
	return (matrix);
}

int	chooseMinDistance(LinkedGraph *lg, int *distance, int *visited)
{
	int min = INT32_MAX;
	int minIdx = -1;

	for (int i = 0; i < lg->maxVertexCount; i++)
	{
		if (distance[i] < min && visited[i] == NOT_VISITED)
		{
			min = distance[i];
			minIdx = i;
		}
	}
	return minIdx;
}

void	print_visited(int *visited, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", visited[i]);
	printf("\n");
}

void	dijkstra(LinkedGraph *lg, int startVertexID)
{
	int *distance = createArray(lg->maxVertexCount);
	int *visited = createArray(lg->maxVertexCount);
	int **matrix = createWeightMatrix(lg);
	int minIdx;
	// 배열 초기화
	for (int i = 0; i < lg->maxVertexCount; i++)
	{
		distance[i] = matrix[startVertexID][i];
		visited[i] = NOT_VISITED;
	}
	// 시작 정점
	distance[startVertexID] = 0;
	visited[startVertexID] = VISITED;
	for (int i = 0; i < lg->maxVertexCount - 1; i++)
	{
		print_visited(visited, lg->maxVertexCount);
		minIdx = chooseMinDistance(lg, distance, visited);
		if (-1 < minIdx)
		{
			visited[minIdx] = VISITED;
			for (int j = 0; j < lg->maxVertexCount; j++)
			{
				if (visited[j] == NOT_VISITED)
					if (distance[minIdx] + matrix[minIdx][j] < distance[j])
						distance[j] = distance[minIdx] + matrix[minIdx][j];
			}
		}
	}
}

int main(void)
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
	dijkstra(lg, 0);
}