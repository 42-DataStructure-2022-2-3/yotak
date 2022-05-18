#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_
#include <unistd.h>
#include <stdlib.h>
typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct	SimCustomerType {
	SimStatus status;
	int nbr;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
}				SimCustomer;

typedef struct SimCustomerNodeType {
	SimCustomer customer;
	struct SimCustomerNodeType *prev;
	struct SimCustomerNodeType *next;
}	SimCustomerNode;

typedef struct SimCustomerQueueType
{
	int maxElementCount;		// �ִ� ���� ����
	int currentElementCount;	// ���� ������ ����
	SimCustomerNode *front;
	SimCustomerNode *rear; // ��� ������ ���� 1���� �迭 ������
} SimCustomerQueue;

SimCustomerQueue* createSimCustomerQueue(int maxElementCount);
SimCustomerNode* createSCQNode(int arrivalTime, int serviceTime, int nbr);
int enqueueSCQ(SimCustomerQueue* pQueue, SimCustomerNode element);
SimCustomerNode *dequeueSCQ(SimCustomerQueue* pQueue);
SimCustomerNode *peekSCQ(SimCustomerQueue* pQueue);
void deleteSimCustomerQueue(SimCustomerQueue* pQueue);
int isSimCustomerQueueFull(SimCustomerQueue* pQueue);
int isSimCustomerQueueEmpty(SimCustomerQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif