#include "linkedstack.h"

char maze[HEIGHT][WIDTH] = {\
	{'1', '1', '1', '1', '1', '1'}, \
	{'s', '0', '0', '0', '0', '1'}, \
	{'1', '0', '1', '1', '1', '1'}, \
	{'1', '0', '0', '0', '0', 'e'}, \
	{'1', '0', '1', '1', '1', '1'}, \
	{'1', '1', '1', '1', '1', '1'}};

void	printMaze(char maze[HEIGHT][WIDTH])
{
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
			printf("%c ", maze[i][j]);
		printf("\n");
	}
}

void	pushValidPath(LinkedStack *pStack, int x, int y)
{
	if (x < 0 || y< 0)
		return;
	if (maze[x][y] != 1 && maze[x][y] != 2)
	{
		MapPosition pos;
		pos.x = x;
		pos.y = y;
		pushLS(pStack, pos);
	}
}

void	findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	MapPosition *go;
	
	*go = startPos;
	while (go->x != endPos.x && go->y != endPos.y)
	{
		pushValidPath(pStack, go->x, (go->y)+1);
		pushValidPath(pStack, go->x, (go->y)-1);
		pushValidPath(pStack, (go->x)+1, go->y);
		pushValidPath(pStack, (go->x)-1, go->y);
		if (isLinkedStackEmpty(pStack) && 갈곳 x)

	}
	if (go->x == endPos.x && go->y == endPos.y)
		printf("This Way\n");
}

int main(void)
{
	LinkedStack	*LS = createLinkedStack();

	
	MapPosition startPos;
	startPos.x = 0;
	startPos.y = 1;

	MapPosition endPos;
	endPos.x = 5;
	endPos.y = 3;
	findPath(maze, startPos, endPos, LS);
}