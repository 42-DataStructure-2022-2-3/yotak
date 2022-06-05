#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../GraphLinkedList/graphlinkedlist.h"

int		*createArray(int maxVertexCount);
int		**createWeightMatrix(LinkedGraph *lg);
void	initWeightMatrix(LinkedGraph *lg, int **matrix);
int		chooseMinDistance(LinkedGraph *lg, int *distance, int *visited);
void	dijkstra(LinkedGraph *lg, int startVertexID);
#endif