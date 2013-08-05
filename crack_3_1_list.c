#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct Stack {
	int size;
	Node *top;
} Stack;

Node *newNode();
Node *initNode(int);
Stack *initStack();
void push(Node *, Stack *);
Node *pop(Stack *);
void clear(Stack *);
void printAll(Stack *);

main()
{
	int test[] = {1,2,3,4,5};
	int n = 0;
	Stack *stack = initStack();
	for (; n < 5; n++) {
		Node *nod = initNode(test[n]);
		push(nod, stack);
	}
	pop(stack);
	printAll(stack);
	return 0;
}

Node *newNode()
{
	return (Node *)malloc(sizeof(Node));
}

Node *initNode(int data)
{
	Node *nod = (Node *)malloc(sizeof(Node));
	nod->data = data;
	return nod;	
}

Stack *initStack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void push(Node *node, Stack *stack)
{
	node->next = stack->top;
	stack->top = node;
	(stack->size)++;
}

Node *pop(Stack *stack)
{
	if (stack->top != NULL && stack->size > 0) {
		Node *temp = stack->top;
		stack->top = temp->next;
		(stack->size)--;
		return temp; 
	}
	return NULL;
}

void clear(Stack *stack)
{
	while (stack->top != NULL) {
		Node *temp = stack->top;
		free(stack->top);
		stack->top= temp->next;
		(stack->size)--;
	}
}

void printAll(Stack *stack)
{
	Node *temp = stack->top;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}