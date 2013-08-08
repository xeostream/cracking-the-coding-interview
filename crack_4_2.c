#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Queue {
	int head;
	int tail;
	int array[MAXSIZE];
} Queue;

Queue *initQueue();
void push(int);
int pop();
int front();
int empty();

Queue *qu;
main()
{
	qu = initQueue();
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", front());
	return 0;
}

Queue *initQueue()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->head = 0;
	q->tail = 0;
	return q;
}

void push(int data)
{
	if (qu->head <= qu->tail && qu->tail < MAXSIZE)
		(qu->array)[(qu->tail)++] = data;
}

int pop()
{
	if (qu->head <= qu->tail && qu->tail < MAXSIZE)
		return (qu->array)[(qu->head)++];
	qu->head = 0;
	qu->tail = -1;
	return -1;
}

int front()
{
	if (qu->head <= qu->tail && qu->tail < MAXSIZE)
		return (qu->array)[qu->head];
	return -1;	
}

int empty()
{
	return (qu->head >= qu->tail && qu->head != 0) ? 1 : 0;
}