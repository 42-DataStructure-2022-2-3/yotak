#include "BinTree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *newTree = (BinTree *)calloc(1, sizeof(BinTree));
	newTree->pRootNode = &rootNode;
}
BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	return (pBinTree->pRootNode);
}
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	return (pNode->pLeftChild);
}
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	return (pNode->pRightChild);
}
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);