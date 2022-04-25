#ifndef _LINKED_STACK_
#define _LINKED_STACK_
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define OPERATOR "()*/+-0"
typedef enum PrecedenceType { lparen, rparen, times, divide, plus, minus, operand} Precedence;
typedef struct StackNodeType
{
	char value;
	Precedence type;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
int checkBracketMatching(char *expression);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif