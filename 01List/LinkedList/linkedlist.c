#include "linkedlist.h"

LinkedList* createLinkedList()
{
	LinkedList	*pList;
	
	pList = (LinkedList *)calloc(1, sizeof(LinkedList));
	return(pList);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode	*curr;
	ListNode	*addNode;
	int			i;

	if (position < 0 || pList->currentElementCount < position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	addNode = (ListNode	*)calloc(1, sizeof(ListNode));
	*addNode = element; 
	curr = &pList->headerNode;
	for (int i = 0; i < position; i++)
		curr = curr->pLink;
	addNode->pLink = curr->pLink;
	curr->pLink = addNode;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;
	ListNode	*delNode;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (FALSE);
	}
	curr = &pList->headerNode;
	for (int i = 0; i < position; i++)
		curr = curr->pLink;
	delNode = curr->pLink;
	curr->pLink = delNode->pLink;
	free(delNode);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode	*curr;

	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("Wrong Approach\n");
		return (NULL);
	}
	curr = &pList->headerNode;
	for (int i = 0; i <= position; i++)
		curr = curr->pLink;
	return (curr);
}

void clearLinkedList(LinkedList* pList)
{
	int position = pList->currentElementCount - 1;
	for (; 0 <= position; position--)
		removeLLElement(pList, position);
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	clearLinkedList(pList);
	free(pList);
}

void displayLinkedList(LinkedList *pList)
{
	ListNode	*pNode;

	pNode = (ListNode *)malloc(sizeof(ListNode));
	pNode = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("%d",pNode->data);
		pNode = pNode->pLink;
		if (i < pList->currentElementCount - 1)
			printf("->");
	}
	printf("\n");
	return ;
}