#include "include/bintree.h"
#include "include/traversal.h"

// void search_node(BinTreeNode *next_node ,int data, BinTreeNode *new_node)
// {
// 	if(date < next_node->data)
// 	{
// 		if(next_node->left == NULL)
// 			next_node->pLeftChild = new_node;
// 		else
// 			search_node(next_node->leit);
// 	}
// 		// search_node(next_node->leit)

// 	else if(date > next_node->data)
// 	{
// 		if(next_node->right == NULL)
// 			next_node->pRightChild = new_node;
// 		else
// 			search_node(next_node->right);
// 	}
// }

//data를 받아 크기 순서대로 트리를 만드는 함수
//root를 받아 새로운 노드를 인자로 준다
void set_node(BinTreeNode *currNode, BinTreeNode *newNode)
{
	if (!currNode || currNode->visited)
		return ;
	currNode->visited = 1;
	if (newNode->data < currNode->pLeftChild->data)
	{
		insertLeftChildNodeBT(currNode, *newNode);
		return ;
	}
	//[left->data] 3
	//[right->data] 5
	//[newNode->data] 4
	else if (currNode->pLeftChild->data < newNode->data && newNode->data < currNode->pRightChild->data)
	{
		insertRightChildNodeBT(currNode, *newNode);
		return ;
	}
	else
	{
		set_node(currNode->pLeftChild, newNode);
		set_node(currNode->pRightChild, newNode);
	}
	
}

int main(void)
{
	BinTree *pTree;
	BinTreeNode *pNode;

	pTree->pRootNode = makeBinTreeNode('0', 0);
	for (int i = 1; i <= 10; i++)
		set_node(pTree->pRootNode, makeBinTreeNode(i + 48, 0));
}