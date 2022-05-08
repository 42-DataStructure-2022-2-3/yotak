#include "../includes/simdef.h"
#include "../includes/simlinkedqueue.h"
#include <signal.h>

Data data;

void openBank() {
	data.isOpen = true;
	data.servTime = 0;
}

void closeBank() {
	data.isOpen = false;
	data.nightTime = 0;
}

void checkworkTime() {
	// if (data.servTime == 11 && data.isOpen == true) closeBank();
	// if (data.nightTime == 13 && data.isOpen == false) openBank();
	printf("지금은 %d 시 입니다.\n", data.servTime + 7);
	// else if (data.isOpen == false && data.nightTime - (int)data.nightTime == 0)
	// 	printf("지금은 밤 %d 시 입니다.\n", ((int)data.nightTime + 18) % 24);
	// if (data.isOpen == true) 
	data.servTime += 1 ;
	// else data.nightTime += 0.5;
}

void exitSimul(int sigint) {
	(void)sigint;
	printf("시뮬레이션이 끝났습니다.");
	deleteSimCustomerQueue(data.servicelist);
	deleteSimCustomerQueue(data.waitlist);
    system("leaks bankSimul");
	exit(0);
}

void run_simulation() {
    SimCustomerNode *nptr;
	static int customerNbr;

	while (1) {
		//printf("windowlist의 노드 개수%d, servicelist의 노드 개수 %d\n", data.windowlist->currentElementCount, data.servicelist->currentElementCount);
		signal(SIGINT, exitSimul);
		printf("지금은 %d 시 입니다.\n", data.servTime + 7);
		int needtime = rand() % 3;
		needtime = (!needtime) ? 1 : needtime;
		nptr = createSCQNode(data.servTime, needtime, customerNbr++);
		printf("%d번 고객이 은행에 입장하셨습니다. 서비스 예상 시간: %d\n", nptr->customer.nbr, needtime);
		enqueueSCQ(data.waitlist, *nptr);
		free(nptr);
		if (isSimCustomerQueueFull(data.servicelist) == false
			&& isSimCustomerQueueEmpty(data.waitlist) == false) {
			nptr = dequeueSCQ(data.waitlist);
			enqueueSCQ(data.servicelist, *nptr);
			printf("%d번 고객이 은행 창구에서 업무를 기다리고 있습니다. 서비스 예상 시간: %d\n", nptr->customer.nbr, needtime);
			free(nptr);
		}
		if (isSimCustomerQueueFull(data.windowlist) == false
			&& isSimCustomerQueueEmpty(data.servicelist) == false)
		{
			nptr = dequeueSCQ(data.servicelist);
			enqueueSCQ(data.windowlist, *nptr);
			data.windowlist->front->customer.startTime = data.servTime;
			data.windowlist->front->customer.endTime = data.servTime + needtime;
			printf("%d번 고객이 은행 창구에서 업무를 보고 있습니다. 서비스 예상 시간: %d\n", data.windowlist->front->customer.nbr, needtime);
			free(nptr);
		}
		if (data.windowlist->front->customer.endTime == data.servTime)
		{
			nptr = dequeueSCQ(data.windowlist);
			printf("%d번 고객이 은행을 나갑니다 %d\n", nptr->customer.nbr, needtime);
			free(nptr);
		}
		data.servTime += 1 ;
		if (data.servTime > 10)
			break ;
		sleep(1);
	}
};


int main(void) {
	srand(time(NULL));
	data.servicelist = createSimCustomerQueue(10);
	data.waitlist = createSimCustomerQueue(30);
	data.windowlist = createSimCustomerQueue(1);
	// openBank();
	data.servTime = 0;
	run_simulation();
    return 0;
}
