#ifndef _LINKED_STACK_
#define _LINKED_STACK_
# include <stdio.h>
# include <stdlib.h>
typedef struct StackNodeType
{
	int	x;
	int	y;
	struct StackNodeType* pLink;
} PosNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	PosNode* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, PosNode element);
PosNode* popLS(LinkedStack* pStack);
PosNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif