#ifndef _LINKED_STACK_
#define _LINKED_STACK_
# include <stdio.h>
# include <stdlib.h>
#define HEIGHT 6
#define WIDTH 6
typedef struct StackNodeType
{
	int x;
	int y;
	struct StackNodeType* pLink;
} MapPosition;

typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack();
int 		pushLS(LinkedStack* pStack, MapPosition element);
MapPosition* popLS(LinkedStack* pStack);
MapPosition* peekLS(LinkedStack* pStack);
void 	deleteLinkedStack(LinkedStack* pStack);
int 	isLinkedStackFull(LinkedStack* pStack);
int 	isLinkedStackEmpty(LinkedStack* pStack);
void	findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
void	showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void	printMaze(char maze[HEIGHT][WIDTH]);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif