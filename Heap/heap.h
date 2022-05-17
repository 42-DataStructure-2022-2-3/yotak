#ifndef _HEAP_
#define _HEAP_
#include <stdio.h>
#include <stdlib.h>
//MaxHeap
#define MAX_SIZE 42
typedef struct HeapNodeType
{
	int	data;
	int visited;
} HeapNode;
typedef struct HeapType
{
	int maxElementCount;
	int currentElementCount;
	HeapNode *pElement;
} Heap;
Heap *makeHeap(int maxElementCount);
HeapNode *getRootNode(Heap *pHeap);
HeapNode *insertMaxHeap(Heap *pHeap, HeapNode element);
void deleteMaxHeap(Heap *pHeap);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif