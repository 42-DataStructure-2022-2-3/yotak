#ifndef _SIMDEF_H_
#define _SIMDEF_H_

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "simlinkedqueue.h"


// 도착 시각 -> 대기큐에 도착한 시간
// 서비스 시간 -> 소요시간
// 시작 시각 -> 서비스 노드
// 종료 시각: 시작 시각 + 서비스 시간.

typedef struct SimData {
	float servTime;
	float nightTime;
	bool isOpen;
	SimCustomerQueue *waitlist;
	SimCustomerQueue *servicelist;
}	Data;

void insertCutomer(int arrivalTime, int processTime, SimCustomerQueue *pQueue);
void processArrival(int currentTime, SimCustomerQueue *pArrivalQueue, SimCustomerQueue *pWaitQueue);
SimCustomerNode* processServiceNodeStart(int currentTime, SimCustomerQueue *pWaitQueue);
SimCustomerNode* processServiceNodeEnd(int currentTime, SimCustomerNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, SimCustomerQueue *pWaitQueue);
void printReport(SimCustomerQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif // _SIMDEF_H_