#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Node {
	int begin;
	int end;
	char src;
	char bri;
	char des;
} Node;
typedef struct Stack {
	int size;
	Node *array[MAXSIZE];
} Stack;

Stack *initStack();
void push(Stack *, Node *);
Node *pop(Stack *);
Node *top(Stack *);
int empty(Stack *);
Node *initNode(int, int, char, char, char);

main()
{
    int n;
    printf("请输入数字n以解决n阶汉诺塔问题：\n");
    scanf("%d",&n);
	Stack *stack = initStack();
    Node *node = initNode(1, n, 'A', 'B', 'C');
    Node *temp;
    push(stack, node);
    while (empty(stack) == 1) {
    	temp = top(stack);
    	pop(stack);
    	if (temp->begin != temp->end) {
	    	push(stack, initNode(1, (temp->end)-1, 'B', 'A', 'C'));
	    	push(stack, initNode(temp->end, temp->end, 'A', 'B', 'C'));
	    	push(stack, initNode(1, (temp->end)-1, 'A', 'C', 'B'));
	    } else {
    		printf("Move %d from %c to %c\n", temp->end, temp->src, temp->des);
    	}
    }
    return 0;
}

Stack *initStack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->size = 0;
	return stack;
}

void push(Stack *stack, Node *node)
{
	if (stack->size < MAXSIZE) {
		(stack->array)[(stack->size)++] = node;
	}
}

Node *pop(Stack *stack)
{
	if (stack->size > 0) {
		return (stack->array)[--(stack->size)];
	}
	return NULL;
}

Node *top(Stack *stack)
{
	if (stack->size > 0)
		return (stack->array)[(stack->size)-1];
	return NULL;
}

int empty(Stack *stack)
{
	return (stack->size) > 0?1:0;
}

Node *initNode(int beg, int e, char src, char bri, char des)
{
	Node *nod = (Node *)malloc(sizeof(Node));
	nod->begin = beg;
	nod->end = e;
	nod->src = src;
	nod->bri = bri;
	nod->des = des;
	return nod;
}
