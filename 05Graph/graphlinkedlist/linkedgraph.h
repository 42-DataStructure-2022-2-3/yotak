#ifndef _LINKED_GRAPH_H
#define _LINKED_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"

typedef struct LinkedGraphType {
    int maxVertexCount;
    int currentVertexCount;
    int currentEdgeCount;
    int graphType;
    LinkedList **ppAdjEdge;
    int *pVertex;
} LinkedGraph;

LinkedGraph *createLinkedGraph(int maxVertexCount);
LinkedGraph *createLinkedDirectedGraph(int maxVertexCount);
int checkVertexValid(LinkedGraph *pGraph, int vertexID);
int addVertexLG(LinkedGraph *pGraph, int vertexID);
int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);
int addEdgeWithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight);

void deleteLinkedGraph(LinkedGraph *pGraph);

int isEmptyLG(LinkedGraph *pGraph);


int removeVertexLG(LinkedGraph *pGraph, int vertexID);
int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList *pList, int delVertexID);

int findGraphNodePosition(LinkedList *pList, int vertexID);

int getEdgeCountLG(LinkedGraph *pGraph);

int getVertexCountLG(LinkedGraph *pGraph);

int getMaxVertexCountLG(LinkedGraph *pGraph);

int getGraphTypeLG(LinkedGraph *pGraph);

void displayLinkedGraph(LinkedGraph *pGraph);

#endif


#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE 1
#define FALSE 0

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

# endif 