#include "checkBM.h"

int checkBracketMatching(char *expression)
{
	LinkedStack *LS;
	StackNode element;
	char symbol;
	int i = 0;

	LS = createLinkedStack();
	while (expression[i])
	{
		symbol = expression[i];
		switch(symbol)
		{
			case '(':
			case '[':
			case '{':
			{
				element.data = expression[i];
				pushLS(LS, element);
				break;
			}
			case ')':
			case '}':
			case ']':
			{
				if (isLinkedStackEmpty(LS))
					return (FALSE);
				else{
					if (symbol == ')')
						if (peekLS(LS)->data != '(')
							return (FALSE);
					if (symbol == '}')
					{
						if (peekLS(LS)->data != '{')
							return (FALSE);
					}
					if (symbol == ']')
						if (peekLS(LS)->data != '[')
							return (FALSE);
					popLS(LS);
				}
			}
		}
		i++;
	}
	if (!isLinkedStackEmpty(LS))
		return (FALSE);
	deleteLinkedStack(LS);
	return (TRUE);
}

LinkedStack* createLinkedStack()
{
	LinkedStack *newLS;

	newLS = (LinkedStack *)calloc(1, sizeof(LinkedStack));
	newLS->pTopElement = NULL;
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
	if (pStack->currentElementCount == 0)
		pStack->pTopElement = NULL;
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