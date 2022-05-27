#include "graphlinkedlist.h"

int main(void)
{
	int i = 0;
	LinkedGraph *lg1;

	lg1 = createLinkedDirectedGraph(6);

	for(; i < 6; i++)
		addVertexLG(lg1, i);

	addEdgeLG(lg1, 0, 1);
	addEdgeLG(lg1, 1, 2);
	addEdgeLG(lg1, 2, 3);
	addEdgeLG(lg1, 2, 1);
	addEdgeLG(lg1, 2, 0);
	addEdgeLG(lg1, 3, 4);
	addEdgeLG(lg1, 3, 2);
	addEdgeLG(lg1, 4, 5);
	addEdgeLG(lg1, 5, 3);

	printf("G1: \n");
	displayLinkedGraph(lg1);

	printf("-----remove------\n");
	removeEdgeLG(lg1, 3, 4);
	removeEdgeLG(lg1, 2, 1);
	displayLinkedGraph(lg1);
	deleteLinkedGraph(lg1);
	free(lg1);
	system("leaks linkedgraph");
	return 0;	
}