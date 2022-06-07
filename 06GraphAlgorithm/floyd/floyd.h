#ifndef FLOYD_H
#define FLOYD_H

#include "../GraphLinkedList/graphlinkedlist.h"
#include "../dijkstra/dijkstra.h"

void	floyd(LinkedGraph *lg);
void	displayMatrix(LinkedGraph *lg, int **arr);

#endif