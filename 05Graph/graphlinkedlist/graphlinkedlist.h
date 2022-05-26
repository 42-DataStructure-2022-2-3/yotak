#ifndef _GRAPH_LINKEDLIST_
#define _GRAPH_LINKEDLIST_

typedef struct GraphVertexType
{
	int vertexID;
	int weight;
} GraphVertex;

typedef struct GraphNodeType
{
	GraphVertex data;
	struct ListNodeType* pLink;
} GraphNode;

typedef struct LinkedGraphType
{
	int maxVertexCount;
	int currentElementCount;
	int graphType;
	int	*pVertex;
	GraphNode *ppAdjEdge;
} LinkedGraph;

LinkedGraph* createLinkedGraph();
GraphNode *createListNode(int vertexID, int weight);
int addLGElement(LinkedGraph* pGraph, int position, GraphNode element);
int removeLGElement(LinkedGraph* pGraph, int position);
GraphNode* getLGElement(LinkedGraph* pGraph, int position);

void clearLinkedGraph(LinkedGraph* pGraph);
int getLinkedGraphLength(LinkedGraph* pGraph);
void deleteLinkedGraph(LinkedGraph* pGraph);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif