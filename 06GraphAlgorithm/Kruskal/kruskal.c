#include "../GraphLinkedList/graphlinkedlist.h"

// 간선의 정보를 저장할 리스트 추가
EdgeList	*createList()
{
	EdgeList *el;

	el = (EdgeList *)calloc()
}

void	kruskal(LinkedGraph *lg)
{

}

//가중치가 있는 무방향 그래프 MST로 만드는 알고리즘
int main(void)
{
	LinkedGraph *lg;
	int			*set;

	lg = createLinkedGraph(6);
	set = set_init(6);
	/* 1. 간선 추가 */
	addEdgeWithWeightLG(lg, 0, 2, 3);
	addEdgeWithWeightLG(lg, 0, 1, 4);
	addEdgeWithWeightLG(lg, 1, 2, 2);
	addEdgeWithWeightLG(lg, 2, 3, 1);
	addEdgeWithWeightLG(lg, 3, 4, 1);
	addEdgeWithWeightLG(lg, 3, 5, 5);
	addEdgeWithWeightLG(lg, 4, 5, 6);

	/* 2. 가중치 정렬 */

	/* 3. kruskal */
	kruskal(lg);
	return (0);
}