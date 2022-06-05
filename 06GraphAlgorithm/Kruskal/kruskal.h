#ifndef _GRAPH_LINKEDLIST_
#define _GRAPH_LINKEDLIST_

typedef struct EdgeType
{
	int from;
	int to;
	int	weight;
	Edge *next;
} Edge;

typedef struct EdgeListType
{
	int edgeCount;
	Edge *head;
} EdgeList;

EdgeList	*createList();
int			addElement(EdgeList *pList, EdgeList *element);
#endif