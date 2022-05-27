#include "../GraphLinkedList/graphlinkedlist.h"

int main(void)
{
	int i = 0;
	LinkedGraph *lg1;

	lg1 = createLinkedGraph(8);

	for(; i < 8; i++)
		addVertexLG(lg1, i);

	addEdgeLG(lg1, 0, 1);
	addEdgeLG(lg1, 0, 2);
	addEdgeLG(lg1, 1, 3);
	addEdgeLG(lg1, 1, 4);
	addEdgeLG(lg1, 2, 5);
	addEdgeLG(lg1, 2, 6);
	addEdgeLG(lg1, 3, 7);
	addEdgeLG(lg1, 4, 5);

	printf("G1: \n");
	displayLinkedGraph(lg1);
}