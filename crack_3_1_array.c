#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 300

typedef struct Stack {
	int length;
	int *array;
	int top;
} Stack;

void push(int, Stack *);
int pop(Stack *stack);

main()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	int test[MAXLENGTH] = {0};
	stack->length = 0;
	stack->top = -1;
	stack->array = test;
	push(1, stack);
	push(2, stack);
	push(3, stack);
	pop(stack);
	return 0;
}

void push(int data, Stack *stack)
{
	if (stack->length <= MAXLENGTH) {
		(stack->length)++;
		(stack->top)++;
		(stack->array)[stack->top] = data;
	}
}

int pop(Stack *stack)
{
	if (stack->length > 0) {
		printf("%d\n", (stack->array)[stack->top]);
		(stack->length)--;
		(stack->top)--;
		return 1;
	}
	return 0;
}