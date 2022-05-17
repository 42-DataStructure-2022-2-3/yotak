#include "heap.h"

Heap *makeHeap(int maxElementCount)
{
	Heap *newHeap;
	HeapNode *pElement;

	newHeap = (Heap *)calloc(1, sizeof(Heap));
	pElement = (HeapNode *)calloc(maxElementCount, sizeof(HeapNode));
	newHeap->maxElementCount = maxElementCount;
	newHeap->pElement = pElement;
	return (newHeap);
}
HeapNode *getRootNode(Heap *pHeap)
{
	return (&pHeap->pElement[1]);
}
HeapNode *insertMaxHeap(Heap *pHeap, HeapNode element)
{
	HeapNode *newNode = (HeapNode *)calloc(1, sizeof(HeapNode));
	int i = ++pHeap->currentElementCount;
	newNode->data = element.data;
	//트리의 마지막에 임시 저장
	pHeap->pElement[i] = *newNode;
	//부모 노드와 키 값 비교 및 이동
	while ((i != 1) && newNode->data > pHeap->pElement[i / 2].data)
	{
		pHeap->pElement[i] = pHeap->pElement[i / 2];
		i /= 2;
	}
	return (newNode);
}
void deleteMaxHeap(Heap *pHeap)
{
	
}
