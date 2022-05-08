#include "../includes/simlinkedqueue.h"

SimCustomerQueue* createSimCustomerQueue(int maxElementCount)
{
	SimCustomerQueue *queue = (SimCustomerQueue *)calloc(sizeof(SimCustomerQueue), 1);
	if (!queue)
		return (NULL);
	queue->maxElementCount = maxElementCount;
	queue->currentElementCount = 0;
	return (queue);
}

SimCustomerNode* createSCQNode(int arrivalTime, int serviceTime, int nbr) {
	SimCustomerNode *newNode = (SimCustomerNode *)calloc(sizeof(SimCustomerNode), 1);
	newNode->customer.arrivalTime = arrivalTime;
	newNode->customer.serviceTime = serviceTime;
	newNode->customer.nbr = nbr;
	return newNode;
}

int enqueueSCQ(SimCustomerQueue* pQueue, SimCustomerNode element)
{
	SimCustomerNode *newNode = createSCQNode(
							element.customer.arrivalTime,
							element.customer.serviceTime,
							element.customer.nbr);
	if (!newNode) return (FALSE);

	if (isSimCustomerQueueEmpty(pQueue))
	{
		pQueue->front = newNode;
		pQueue->rear = newNode;
		pQueue->currentElementCount++;
	}
	else
	{
		newNode->prev = pQueue->rear;
		pQueue->rear->next = newNode;
		pQueue->rear = newNode;
		pQueue->currentElementCount++;
	}
	return (TRUE);
}
SimCustomerNode *dequeueSCQ(SimCustomerQueue* pQueue)
{
	SimCustomerNode *delNode;

	if (isSimCustomerQueueEmpty(pQueue)) return NULL;
	if (pQueue->currentElementCount == 1)
	{
		delNode = pQueue->front;
		pQueue->front = NULL;
		pQueue->rear = NULL;
		pQueue->currentElementCount--;
		return (delNode);
	}
	else
	{
		delNode = pQueue->front;
		pQueue->front = pQueue->front->next;
		pQueue->front->prev = NULL;
		pQueue->currentElementCount--;
		return (delNode);
	}
}
SimCustomerNode *peekSCQ(SimCustomerQueue* pQueue)
{
	return (pQueue->front);
}
void deleteSimCustomerQueue(SimCustomerQueue* pQueue)
{
	for (int i = 0; i < pQueue->currentElementCount; i++)
	{
		free(dequeueSCQ(pQueue));
	}
	free(pQueue);
}

int isSimCustomerQueueFull(SimCustomerQueue* pQueue) {
	return (pQueue->currentElementCount == pQueue->maxElementCount);
}

int isSimCustomerQueueEmpty(SimCustomerQueue* pQueue) {
	return (pQueue->currentElementCount == 0);
}