#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct HeapNodeType
{
	int	key;
	int visited;
} HeapNode;
typedef struct HeapType
{
	int maxElementCount;
	int currentElementCount;
	HeapNode *pElement;
} Heap;

Heap 		*makeHeap(int maxElementCount);
HeapNode 	*getRootNode(Heap *pHeap);
int			insertMinHeap(Heap *pHeap, HeapNode element);
int			deleteMinHeap(Heap *pHeap);
HeapNode 	popMinHeapNode(Heap *pHeap);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0


#endif
