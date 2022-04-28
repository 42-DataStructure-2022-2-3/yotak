#include "posstack.h"

int maze[HEIGHT][WIDTH] = {\
	{1, 1, 1, 1}, \
	{0, 0, 0, 1}, \
	{1, 1, 0, 1}, \
	{1, 0, 0, 0}};

void	printMaze(int maze[HEIGHT][WIDTH])
{
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
			printf("%d ", maze[i][j]);
		printf("\n");
	}
}

int	findPath(int maze[HEIGHT][WIDTH], MapPosition start, MapPosition end, LinkedStack *LS)
{
	MapPosition next;

	if (start.x < 0 || start.y < 0 || start.x >= HEIGHT || start.y >= WIDTH)
		return 0;
	else if (maze[start.x][start.y] != NOT_VISIT)
		return 0;
	else if (start.x == end.x && start.y == end.y)
	{
		maze[start.x][start.y] = VISIT;
		printf("This Way\n");
		return 1;
	}
	else 
	{
		maze[start.x][start.y] = VISIT;
		for (int i =  0; i < NUM_DIRECTIONS; i++)
		{
			int next_x = start.x + DIRECTION_OFFSETS[i][0];
			int next_y = start.y + DIRECTION_OFFSETS[i][1];

			next.x = next_x;
			next.y = next_y;
			pushLS(LS, next);
			if (findPath(maze, next, end, LS))
				return 1;
			free(popLS(LS));
		}
	}
	maze[start.x][start.y] = BLOCKED;
	return 0;
}

void showPath(LinkedStack *pStack)
{
	LinkedStack *cpR = createLinkedStack();

	printf("LS : %d\n", pStack->currentElementCount);
	while (pStack->currentElementCount != 0)
		pushLS(cpR, *popLS(pStack));
	printf("cpR : %d\n", cpR->currentElementCount);
	
	MapPosition *curr;
	curr = cpR->pTopElement->pLink;
	for (int i = 0; i < cpR->currentElementCount - 1; i++)
	{
		printf("(%d, %d) -> ", curr->x, curr->y);
		curr = curr->pLink;
	}
	free(cpR);
}

int	main(void)
{
	LinkedStack *LS;
	MapPosition start;
	MapPosition end;

	LS = createLinkedStack();
	start.x = 1;
	start.y = 0;
	pushLS(LS, start);

	end.x = 3;
	end.y = 3;
	findPath(maze, start, end, LS);
	printMaze(maze);
	showPath(LS);
	return 0;
}
