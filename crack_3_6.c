#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 100

typedef struct Stack {
	int size;
	int array[MAXLENGTH];
} Stack;

Stack *initStack();
void push(Stack *, int);
int pop(Stack *);
int empty(Stack *);
void sort(int[], int);
void swap(int *, int *);

main()
{
	Stack *stack = initStack();
	push(stack, 0);
	push(stack, 3);
	push(stack, 1);
	int temp[MAXLENGTH] = {-1};
	int n = 0;
	while (empty(stack) == 1) {
		temp[n++] = pop(stack);
	}
	sort(temp, n);
	int m = 0;
	for (; m < n; m++) {
		push(stack, temp[m]);
		printf("%d ", temp[m]);
	}
	printf("\n");
	printf("%d\n", pop(stack));
	return 0;
}

Stack *initStack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->size = 0;
	return stack;
}

void push(Stack *stack, int data)
{
	if (stack->size < MAXLENGTH)
		(stack->array)[(stack->size)++] = data;
}

int pop(Stack *stack)
{
	if (stack->size > 0)
		return (stack->array)[--(stack->size)];
	return -1;
}

int empty(Stack *stack)
{
	return (stack->size) > 0 ? 1 : 0;
}

void sort(int temp[], int n)
{
	int i = 0;
	int j;
	for (; i < n; i++) {
		j = i + 1;
		for (; j < n; j++) {
			if (temp[i] > temp[j])
				swap(&temp[i], &temp[j]);
		}
	}
	i = 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}