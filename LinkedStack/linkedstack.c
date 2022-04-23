#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *newLS;

	newLS = (LinkedStack *)calloc(1, sizeof(LinkedStack));
	newLS->currentElementCount = 0;
	newLS->pTopElement = NULL;
	return (newLS);
}

StackNode* createStackNode()
{
	StackNode *newNode;

	newNode = (StackNode *)calloc(1, sizeof(StackNode));
	return (newNode);
}

int	pushLS(LinkedStack* pStack, StackNode element)
{
	if (isLinkedStackFull(pStack))
		return (FALSE);
	if (pStack->pTopElement == NULL)
		pStack->pTopElement = &element;
	else
	{
		StackNode	*top;
		top = pStack->pTopElement;
		pStack->pTopElement = &element;
		element.pLink = top;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	if (!(pStack->currentElementCount))
		return (NULL);
	StackNode	*popNode;
	popNode = pStack->pTopElement;
	pStack->pTopElement = popNode->pLink;
	--(pStack->currentElementCount);
	return (popNode);
}

StackNode* peekLS(LinkedStack* pStack)
{
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode	*delNode;

	while (pStack->pTopElement)
	{
		delNode = popLS(pStack);
		free(delNode);
	}
	pStack->currentElementCount = 0;
}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (FALSE);
}
int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->pTopElement == NULL);
}