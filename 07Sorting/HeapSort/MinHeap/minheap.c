#include "minheap.h"

Heap *makeHeap(int maxElementCount)
{
	Heap *pHeap;
	pHeap = (Heap *)calloc(1, sizeof(Heap));
	pHeap->pElement = (HeapNode *)calloc(maxElementCount, sizeof(HeapNode));
	pHeap->maxElementCount = maxElementCount;

	return (pHeap);
}

HeapNode *getRootNode(Heap *pHeap)
{
	if (pHeap && pHeap->currentElementCount > 0)
		return (&pHeap->pElement[0]);
	else
		return (NULL);
}
//TRUE, FALSE
int	insertMinHeap(Heap *pHeap, HeapNode element)
{
	if (pHeap->currentElementCount == pHeap->maxElementCount)
		return (FALSE);
	// i == 4
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
HeapNode popMinHeapNode(Heap *pHeap)
{
	HeapNode popNode = pHeap->pElement[0];
	HeapNode tmpNode;

	pHeap->currentElementCount--;
	int	i = pHeap->currentElementCount;
	tmpNode = pHeap->pElement[i];
	//마지막 노드를 맨 위로
	// pHeap->pElement[0] = tmpNode;
	//키값을 비교하며 이동
	int parent, child;
	parent = 0;
	//child가 부모 자리에 올릴 노드!
	child = 1;
	// 1이 4가 될 때까지
	while (child <= pHeap->currentElementCount)
	{
		if (child < pHeap->currentElementCount
			&& pHeap->pElement[child].key > pHeap->pElement[child + 1].key)
			child += 1;
		// 부모가 자식보다 작은 경우
		if (tmpNode.key <= pHeap->pElement[child].key)
			break;
		pHeap->pElement[parent] = pHeap->pElement[child];
		parent = child;
		child *= 2;
	}
	pHeap->pElement[parent] = tmpNode;
	return (popNode);
}
//TRUE, FALSE //Heap자체를 삭제
int	deleteMinHeap(Heap *pHeap)
{
	free(pHeap->pElement);
	free(pHeap);
	return (TRUE);
}