#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *newLS;
	StackNode   *newNode; //더미노드

	newLS = (LinkedStack *)calloc(1, sizeof(LinkedStack));
	newNode = (StackNode *)calloc(1, sizeof(StackNode));
	newLS->pTopElement = newNode;
	newNode->data = 0;
	newNode->pLink = NULL;
	return (newLS);
}

int	pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *newNode;

	newNode = (StackNode *)calloc(1, sizeof(StackNode));
	*newNode = element;
	if (pStack->pTopElement == NULL)
		pStack->pTopElement = newNode;
	else
	{
		newNode->pLink = pStack->pTopElement;
		pStack->pTopElement = newNode;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
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
	if (isLinkedStackEmpty(pStack))
		return ;

	StackNode	*delNode;

	while (pStack->pTopElement)
	{
		delNode = popLS(pStack);
		free(delNode);
		--(pStack->currentElementCount);
	}
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->pTopElement == NULL);
}