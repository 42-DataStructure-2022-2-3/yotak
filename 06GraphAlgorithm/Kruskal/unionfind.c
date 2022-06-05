#include "unionfind.h"

// 집합 배열 -1로 초기화 => -1값이 루트노드임
int	*set_init(int maxVertices)
{
	int	*set;

	set = (int *)malloc(sizeof(int));
	for (int i = 0; i < maxVertices; i++)
		set[i] = -1;
	return (set);
}

// 속하는 집합의 루트 노드를 반환
int	set_find(int *set, int curr)
{
	// 속하는 집합이 없다면 자기 자신의 인덱스를 반환
	if (set[curr] == -1)
		return curr;
	// 속하는 집합이 있으면 찾아가기
	while (set[curr] != -1)
		curr = set[curr];
	return curr;
}

// 2개의 집합을 합친다
void	set_union(int *set, int node_a, int node_b)
{
	int root1 = set_find(set, node_a);
	int root2 = set_find(set, node_b);

	if (root1 != root2)
		set[root1] = root2;
}