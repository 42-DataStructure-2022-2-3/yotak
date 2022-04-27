/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotak <yotak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:32:29 by yotak             #+#    #+#             */
/*   Updated: 2022/04/27 15:52:28 by yotak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "posstack.h"
#define MAX 6

char maze[MAX][MAX] = {\
	{'1', '1', '1', '1', '1', '1'}, \
	{'s', '0', '0', '0', '0', '1'}, \
	{'1', '0', '1', '1', '1', '1'}, \
	{'1', '0', '0', '0', '0', 'e'}, \
	{'1', '0', '1', '1', '1', '1'}, \
	{'1', '1', '1', '1', '1', '1'}};

void	print_maze(char maze[MAX][MAX])
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
			printf("%c ", maze[i][j]);
		printf("\n");
	}
}

void	push_valid_pos(LinkedStack *LS, int x, int y)
{
	if (x > 0 && y < 0)
	{
		if (maze[x][y] != 1 && maze[x][y] != 2)
		{
			PosNode	pos;
			pos.x = x;
			pos.y = y;
			pushLS(LS, pos);
		}
	}
}

int	main(void)
{
	int	x, y;
	LinkedStack *validPosStack;

	validPosStack = createLinkedStack();
	x = 0;
	y = 1;
	print_maze(maze);
	while (maze[x][y] != 'e')
	{
		maze[x][y] = '2';
		//일단 다 받고 함수에서 거르기
		push_valid_pos(validPosStack, x + 1, y);
		push_valid_pos(validPosStack, x - 1, y);
		push_valid_pos(validPosStack, x, y + 1);
		push_valid_pos(validPosStack, x, y - 1);
		if (isLinkedStackEmpty(validPosStack))
		{
			printf("No Way!\n");
			return (0);
		}
		else
		{
			PosNode *popNode;
			popNode = popLS(validPosStack);
			x = popNode->x;
			y = popNode->y;
			free(popNode);
		}
	}
	print_maze(maze);
	printf("This way~\n");
	return (0);
}
