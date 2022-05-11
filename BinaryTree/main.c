#include "BinTree.h"

int main(void)
{
	BinTree *pTree;
	BinTreeNode *pRoot;
	BinTreeNode *pBnode;
	BinTreeNode *pCnode;
	BinTreeNode *pNode;
	BinTreeNode *pElement;

	// A Root
	pRoot = makeBinTreeNode('A', 0);
	// pTree
	pTree = makeBinTree(*pRoot);
	printf("Check RootNode : [%c]\n", pTree->pRootNode->data);
	// pNode = getRootNodeBT(pTree);
	// Left B Node
	pElement = makeBinTreeNode('B', 0);
	pBnode = insertLeftChildNodeBT(pRoot, *pElement);
	pNode = getLeftChildNodeBT(pRoot);
	free(pElement);
	printf("Check LeftChildNode : [%c]\n", pNode->data);
	// Right C Node
	pElement = makeBinTreeNode('C', 0);
	pCnode = insertRightChildNodeBT(pRoot, *pElement);
	pNode = getRightChildNodeBT(pRoot);
	free(pElement);
	printf("Check RightChildNode : [%c]\n", pNode->data);
	if (pBnode != NULL) {
		pElement = makeBinTreeNode('D', 0);
		insertLeftChildNodeBT(pBnode, *pElement);
		pNode = getLeftChildNodeBT(pBnode);
		free(pElement);
		printf("Check B->LeftChildNode : [%c]\n", pNode->data);
	}
	if (pCnode != NULL) {
		pElement = makeBinTreeNode('E', 0);
		insertLeftChildNodeBT(pCnode, *pElement);
		pNode = getLeftChildNodeBT(pCnode);
		free(pElement);
		printf("Check C->LeftChildNode : [%c]\n", pNode->data);

		pElement = makeBinTreeNode('F', 0);
		insertRightChildNodeBT(pCnode, *pElement);
		pNode = getRightChildNodeBT(pCnode);
		free(pElement);
		printf("Check C->RightChildNode : [%c]\n", pNode->data);
	}
	printf("Check RootNode : [%c]\n", pTree->pRootNode->data);
	deleteBinTree(pTree);
	system("leaks a.out");
}