#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 100

typedef struct Stack {
	int size;
	int array[MAXLENGTH];
} Stack;
typedef struct Deque {
	Stack *in;
	Stack *out;
} Deque;

Stack *initStack();
void push(Stack *, int);
int pop(Stack *);
int empty(Stack *);
Deque *initDeque(Stack *, Stack *);
void ins(Deque *, int);
int outs(Deque *);

main()
{
	Stack *in = initStack(), *out = initStack();
	Deque *deque = initDeque(in, out);
	ins(deque, 0);
	ins(deque, 1);
	ins(deque, 2);
	outs(deque);
	printf("%d\n", outs(deque));
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

Deque *initDeque(Stack *in, Stack *out)
{
	Deque *deque = (Deque *)malloc(sizeof(Deque));
	deque->in = in;
	deque->out = out;
	return deque;
}

void ins(Deque *deque, int data)
{
	if ((deque->in)->size < MAXLENGTH)
		((deque->in)->array)[((deque->in)->size)++] = data;
}

int outs(Deque *deque)
{
	if ((deque->out)->size == 0) {
		int n = (deque->in)->size;
		int temp;
		for (; n > 0; n--) {
			temp = pop(deque->in);
			//printf("%d\n", temp);
			push(deque->out, temp);
		}
	}
	return ((deque->out)->array)[--((deque->out)->size)]; 
}