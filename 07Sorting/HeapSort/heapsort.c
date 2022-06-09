#include "MinHeap/minheap.h"

int main()
{
	Heap *heap = makeHeap(5);
	HeapNode buf;
	buf.key = 1;
	insertMinHeap(heap, buf);
	buf.key = 4;
	insertMinHeap(heap, buf);
	buf.key = 2;
	insertMinHeap(heap, buf);
	buf.key = 5;
	insertMinHeap(heap, buf);
	buf.key = 7;
	insertMinHeap(heap, buf);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", popMinHeapNode(heap).key);
	}
	printf("\n");
}