#include "posstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *newLS;

	newLS = (LinkedStack *)calloc(1, sizeof(LinkedStack));
	newLS->pTopElement = NULL;
	return (newLS);
}

int	pushLS(LinkedStack* pStack, PosNode element)
{
	PosNode *newNode;

	newNode = (PosNode *)calloc(1, sizeof(PosNode));
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

PosNode* popLS(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	PosNode	*popNode;
	popNode = pStack->pTopElement;
	pStack->pTopElement = popNode->pLink;
	--(pStack->currentElementCount);
	return (popNode);
}

PosNode* peekLS(LinkedStack* pStack)
{
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return ;

	PosNode	*delNode;

	while (pStack->pTopElement)
	{
		delNode = popLS(pStack);
		free(delNode);
		--(pStack->currentElementCount);
	}
	free(pStack);
}

int isLinkedStackFull()
{
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->pTopElement == NULL);
}
