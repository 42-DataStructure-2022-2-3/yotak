#ifndef _GRAPH_LINKEDLIST_
#define _GRAPH_LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>

int		*set_init(int maxVertices);
int		set_find(int *set, int curr);
void	set_union(int *set, int node_a, int node_b);
#endif