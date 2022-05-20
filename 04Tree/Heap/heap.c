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
	newNode->key = element.key;
	//트리의 마지막에 임시 저장
	pHeap->pElement[i] = *newNode;
	//부모 노드와 키 값 비교 및 이동
	while ((i != 1) && newNode->key > pHeap->pElement[i / 2].key)
	{
		pHeap->pElement[i] = pHeap->pElement[i / 2];
		i /= 2;
	}
	return (newNode);
}
//최대값을 가진 요소 삭제
HeapNode *deleteMaxHeap(Heap *pHeap)
{
	int parent, child;
	HeapNode *delNode, *pHeapNode;

	parent = 1;
	child = 2;
	delNode = &pHeap->pElement[parent];
	pHeapNode = &pHeap->pElement[(pHeap->currentElementCount)--];
	while (child <= pHeap->currentElementCount)
	{
		if ((child < pHeap->currentElementCount)
			&& pHeap->pElement[child].key < pHeap->pElement[child+1].key) {
				child++;
			}
		if (pHeap->pElement[child].key <= pHeapNode->key)
			break;
		pHeap->pElement[parent] = pHeap->pElement[child];
		parent = child;
		child *= 2;
	}
	pHeap->pElement[parent] = *pHeapNode;
	return (delNode);
}
