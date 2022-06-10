#include "MinHeap/minheap.h"

int main()
{
	Heap *heap = makeHeap(5);
	HeapNode buf;
	buf.key = 1;
	insertMinHeap(heap, buf);
	buf.key = 4;
	insertMinHeap(heap, buf);
	buf.key = 3;
	insertMinHeap(heap, buf);
	buf.key = 0;
	insertMinHeap(heap, buf);
	buf.key = 7;
	insertMinHeap(heap, buf);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", popMinHeapNode(heap).key);
	}
	printf("\n");
	system("leaks heapsort");
}
