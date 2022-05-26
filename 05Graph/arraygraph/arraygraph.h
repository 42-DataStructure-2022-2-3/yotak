#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_
//인접 행렬로 구현하기   
typedef struct ArrayGraphType
{
	int maxVertexCount;		// 최대 노드 개수
	int currentVertexCount;	// 현재 노드 개수
	int graphType;			// 방향 그래프, 무방향 그래프
	int **ppAdjEdge;		// 간선 저장을 위한 배열 포인터
	int *pVertex;			// 노드 저장을 위핸 포인터
} ArrayGraph;

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph);

int isEmptyAG(ArrayGraph* pGraph);

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID);

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// USED || NOT_USED
int checkVertexValid(ArrayGraph* pGraph, int vertexID);

// 노드 삭제
int removeVertexAG(ArrayGraph* pGraph, int vertexID);

// 간선 삭제
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

void displayArrayGraph(ArrayGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
