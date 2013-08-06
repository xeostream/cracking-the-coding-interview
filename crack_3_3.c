#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100
#define MAXARRAY 2

typedef struct Stack {
	int size;
	int array[MAXARRAY];
} Stack;

Stack *stacks[MAXSTACK];
int position;

Stack *initStack();
void push(int);
int pop();
int popAt(int);

main()
{
	stacks[0] = initStack();
	position = 0;
	push(0);
	push(1);
	push(2);
	printf("%d\n", position);
	int temp = popAt(0);
	printf("%d %d\n", temp, position);
	return 0;
}

Stack *initStack() 
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->size = 0;
	return stack;
}

void push(int data)
{
	if (stacks[position]->size == MAXARRAY)
		stacks[++position] = initStack();
	(stacks[position]->array)[stacks[position]->size] = data;
	(stacks[position]->size)++;
}

int pop()
{
	int temp = position;
	if (stacks[position]->size == 1)
		return (temp = (stacks[position--]->array)[--(stacks[temp]->size)]);
	return (temp = stacks[position]->array[--(stacks[position]->size)]);
}

int popAt(int index)
{
	if (index > position) return -1;
	while (stacks[index]->size == 0)
		--index;
	return (stacks[index]->array)[--(stacks[index]->size)];	
} 