#include "doublyList.h"

int main(void)
{
	DoublyList *doubly = createDoublyList();
	int	max;

	max = 4;
	for(int i = 0; i < max; i++)
	{	
		DoublyListNode 	pNode;
		pNode.data = i * 4 ;
		pNode.pLLink = NULL;
		pNode.pRLink = NULL;
		addDLElement(doubly, i, pNode);
	}
	displayDoublyList(doubly);
	removeDLElement(doubly, 2);
	printf("%d\n", getDLElement(doubly, 2)->pLLink->data);
	clearDoublyList(doubly);
	displayDoublyList(doubly);
	system("leaks a.out");

	return (0);
}