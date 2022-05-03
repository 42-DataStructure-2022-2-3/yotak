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
	if (data.servTime == 11 && data.isOpen == true) closeBank();
	if (data.nightTime == 13 && data.isOpen == false) openBank();
	if (data.isOpen == true && data.servTime - (int)data.servTime == 0)
		printf("지금은 낮 %d 시 입니다.\n", (int)data.servTime + 7);
	else if (data.isOpen == false && data.nightTime - (int)data.nightTime == 0)
		printf("지금은 밤 %d 시 입니다.\n", ((int)data.nightTime + 18) % 24);
	if (data.isOpen == true) data.servTime += 0.5 ;
	else data.nightTime += 0.5;
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
		signal(SIGINT, exitSimul);
		if (data.isOpen && (int)data.servTime % 2) {
			int needtime = rand() % 3;
			needtime = (!needtime) ? 1 : needtime;
			nptr = createSCQNode(data.servTime, needtime, customerNbr++);
			printf("%d번 고객이 은행에 입장하셨습니다. %d\n", nptr->customer.nbr, needtime);
			enqueueSCQ(data.waitlist, *nptr);
			free(nptr);
			if (isSimCustomerQueueFull(data.servicelist) == false
				&& isSimCustomerQueueEmpty(data.waitlist) == false) {
				nptr = dequeueSCQ(data.waitlist);
				enqueueSCQ(data.servicelist, *nptr);
				printf("%d번 고객이 은행 창구에서 업무를 보고 있습니다. %d\n", nptr->customer.nbr, needtime);
				free(nptr);
			}
			if ()
		}
		checkworkTime();
		usleep(500000);
    }
};


int main(void) {
	srand(time(NULL));
	data.servicelist = createSimCustomerQueue(10);
	data.waitlist = createSimCustomerQueue(30);
	
	openBank();
	run_simulation();
    return 0;
}
