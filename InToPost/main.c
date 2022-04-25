#include "linkedstack.h"

int main(void)
{
	LinkedStack *LS = createLinkedStack();
	int	i = 0;
	char *str = "(a * b)";

	if (checkBracketMatching(str))
	{
		printf("Bracket ERROR!\n");
		return (0);
	}
	while(str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		else if (!strchr(OPERATOR,str[i]))
			printf("%c ", str[i]);
		else
		{
			StackNode newNode;
			newNode.value = str[i];
			switch(newNode.value)
			{
				case('('):
					newNode.type = lparen;
					break;
				case(')'):
				{
					while (LS->currentElementCount != 0 && LS->pTopElement->type != 0)
					{
						printf("%c ", OPERATOR[popLS(LS)->type]);
					}
					break;
				}
				case('*'):
				{
					if (isLinkedStackEmpty(LS))
					{
						printf("Push to Empty List\n");
						newNode.type = times;
					}
					else
					{
						StackNode *curr;
						curr = LS->pTopElement;
						while (curr->pLink != NULL && curr->type <= 3)
						{
							printf("%c ", OPERATOR[popLS(LS)->type]);
							curr = curr->pLink;
						}
					}
					break;
				}
				// case('/'):
				// 	if (isLinkedStackEmpty(LS))
				// 		newNode.type = divide;
				// 	else
				// 		while (LS->pTopElement->type <= 3)
				// 		{
				// 			printf("%c ", OPERATOR[popLS(LS)->type]);
				// 		}
				// 	break;
				// case('+'):
				// 	if (isLinkedStackEmpty(LS))
				// 		newNode.type = plus;
				// 	else
				// 		while (LS->pTopElement->type <= 5)
				// 		{
				// 			printf("%c ", OPERATOR[popLS(LS)->type]);
				// 		}
				// 	break;
				// case('-'):
				// 	if (isLinkedStackEmpty(LS))
				// 		newNode.type = minus;
				// 	else
				// 		while (LS->pTopElement->type <= 5)
				// 		{
				// 			printf("%c ", OPERATOR[popLS(LS)->type]);
				// 		}
				// 	break;
			}
			pushLS(LS, newNode);
			// printf("Current Element Count : %d\n", LS->currentElementCount);
		}
		i++;
	}
	if (!isLinkedStackEmpty(LS))
	{
		// printf("Stack is not Empty\n");
		while (LS->currentElementCount != 0)
			printf("%c ", OPERATOR[popLS(LS)->type]);
	}
	printf("\n");
	return (0);
}