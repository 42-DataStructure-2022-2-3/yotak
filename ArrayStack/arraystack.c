#include "arraystack.h"

ArrayStack* createArrayStack(int max)
{
	ArrayStack *newAS;

	newAS = (ArrayStack *)calloc(1, sizeof(ArrayStack));
	newAS->maxElementCount = max;
	newAS->currentElementCount = 0;
	newAS->array = NULL;
}

int isArrayStackFull(ArrayStack *pStack)
{
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack *pStack)
{
	return (pStack->currentElementCount == 0);
}

StackNode* createStackNode(char data)
{
	StackNode *newNode;

	newNode = (StackNode *)calloc(1, sizeof(StackNode));
	newNode->data = data;
}

int pushAS(ArrayStack *pStack, StackNode element)
{
	if (isArrayStackFull(pStack))
	{
		printf("[ERROR] Stack is Full!\n");
		return (FALSE);
	}
	else
	{
		pStack->array[pStack->currentElementCount] = element;
		pStack->currentElementCount++;
	}
}

StackNode* popAS(ArrayStack *pStack)
{
	StackNode *popNode;

	if (isArrayStackEmpty(pStack))
		return (NULL);
	popNode = &pStack->array[pStack->currentElementCount - 1];
	--(pStack->currentElementCount);
	return (popNode);
}

StackNode* peekAS(ArrayStack *pStack)
{
	if (isArrayStackEmpty(pStack))
		return (NULL);
	return (&pStack->array[pStack->currentElementCount - 1]);
}

void deleteArrayStack(ArrayStack *pStack)
{
	int	i;

	i = pStack->currentElementCount;
	while (0 <= i)
	{
		freee(pStack->array[i]);
		i--;
	}
	free(pStack);
}