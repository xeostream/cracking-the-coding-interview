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

Node *initNode(int);
Stack *initStack();
void push(Node *, Stack *, Stack *);
void pushMin(Node *, Stack *);
Node *pop(Stack *, Stack *);
Node *popMin(Stack *);
void printAll(Stack *);

main()
{
	int test[] = {1,5,2,9,8,3,6,8,0,7,1};
	int n = 0;
	Stack *stack = initStack();
	Stack *min = initStack();
	for (; n < 11; n++) {
		Node *nod = initNode(test[n]);
		push(nod, stack, min);
	}
	for (; n > 3; n--) {
		printf("%d %d\n", (stack->top)->data, (min->top)->data);
		pop(stack, min);
	}
	printAll(min);
	return 0;
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

void push(Node *node, Stack *stack, Stack *min)
{
	if (stack->top == NULL)
		pushMin(node, min);
	node->next = stack->top;
	stack->top = node;
	(stack->size)++;
	if (node->data <= (min->top)->data) {
		Node *temp = initNode(node->data);
		pushMin(temp, min);
	}
}

void pushMin(Node *node, Stack *min)
{
	if (min->top == NULL || node->data < (min->top)->data) {
		node->next = min->top;
		min->top = node;
		(min->size)++;	
	}
} 

Node *pop(Stack *stack, Stack *min)
{
	if (stack->top != NULL && stack->size > 0) {
		Node *temp = stack->top;
		stack->top = temp->next;
		(stack->size)--;
		if ((stack->top)->data == (min->top)->data)
			popMin(min);
		return temp; 
	}
	return NULL;
}

Node *popMin(Stack *min)
{
	if (min->top != NULL && min->size > 0) {
		Node *temp = min->top;
		min->top = temp->next;
		(min->size)--;
		return temp;
	}
	return NULL;
}

void printAll(Stack *stack)
{
	Node *temp = stack->top;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}