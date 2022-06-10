#include "minheap.h"

// 힙 구조 생성
Heap *makeHeap(int maxElementCount)
{
	Heap *pHeap;
	pHeap = (Heap *)calloc(1, sizeof(Heap));
	pHeap->pElement = (HeapNode *)calloc(maxElementCount, sizeof(HeapNode));
	pHeap->maxElementCount = maxElementCount;

	return (pHeap);
}
// 0번 노드 반환
HeapNode *getRootNode(Heap *pHeap)
{
	if (pHeap && pHeap->currentElementCount > 0)
		return (&pHeap->pElement[0]);
	else
		return (NULL);
}
// 최소 힙에 요소 삽입
// 맨 끝자리에 배치한 후 부모노드와 크기를 비교하여 자리를 찾아감
int	insertMinHeap(Heap *pHeap, HeapNode element)
{
	// 현재 노드 개수 == 최대 노드 개수
	if (pHeap->currentElementCount == pHeap->maxElementCount)
		return (FALSE);
	int	i = pHeap->currentElementCount;
	while (i != 0)
	{
		//부모 노드와 나의 키값 비교
		if (element.key >= pHeap->pElement[i / 2].key)
			break ;
		pHeap->pElement[i] = pHeap->pElement[i / 2];
		i /= 2;
	}
	pHeap->pElement[i] = element;
	pHeap->currentElementCount++;
	return (TRUE);
}
// 가장 작은 key값을 가지는 맨 처음 노드를 pop
HeapNode popMinHeapNode(Heap *pHeap)
{
	HeapNode popNode = pHeap->pElement[0];
	HeapNode tmpNode;

	pHeap->currentElementCount--;
	int	i = pHeap->currentElementCount;
	tmpNode = pHeap->pElement[i];

	int parent = 0;
	int child = 1;
	while (child <= pHeap->currentElementCount)
	{
		if (child < pHeap->currentElementCount
			&& pHeap->pElement[child].key > pHeap->pElement[child + 1].key)
			child += 1;
		if (tmpNode.key <= pHeap->pElement[child].key)
			break;
		pHeap->pElement[parent] = pHeap->pElement[child];
		parent = child;
		child *= 2;
	}
	pHeap->pElement[parent] = tmpNode;
	return (popNode);
}

int	deleteMinHeap(Heap *pHeap)
{
	free(pHeap->pElement);
	free(pHeap);
	return (TRUE);
}
