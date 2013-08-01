#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list *next;
}list;

list *init(int *, int);
void print(list *);
list *getnode(void);
void getN(list *, int *);
void printN(list *, int);

main()
{
	int n = 10, position = 3;
	int test[] = {3,2,1,3,5,6,2,6,3,1};
	list *first = init(test, n);
	printN(first, position);
	getN(first, &position);
	return 0;
}
list *init(int *test, int n)
{
	list *nod, *p, *head;
	int m;
	for (m = 0; m < n; m++) {
		nod = getnode();
		nod->data = *test++;
		if (m == 0) {
			head = p = nod;
			continue;
		}
		p->next = nod;
		p = nod;
	}
	p->next = NULL;
	return head;
}
list *getnode()
{
	return (list *)malloc(sizeof(list));
}

void getN(list *head, int *position)
{
	if (head->next != NULL)
		getN(head->next, position);
	(*position)--;
	if (*position == 0)
		printf("%d\n", head->data);	
}

void printN(list *head, int n)
{
	list *temp = head;
	while (n >= 1 && temp->next) {
		temp = temp->next;
		n--;
	}
	while (temp) {
		head = head->next;
		temp = temp->next;
	}
	printf("%d\n", head->data);	
}