#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list *next;
}list;

list *init(int *, int);
void print(list *);
list *getnode(void);
list *addlist(list *, list *);

main()
{
	int test[] = {3,2,1,3,5,6,2,6,3,1};
	int test1[] = {1,2,3,4,5};
	list *first = init(test, 10);
	list *second = init(test1, 5);
	list *result = addlist(first, second);
	print(result);
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
void print(list *nod)
{
	while (nod) {
		printf("%d ", nod->data);
		nod = nod->next;
	}
	printf("\n");
}

list *addlist(list *first, list *second)
{
	if (first == NULL) return second;
	if (second == NULL) return first;
	list *one = first, *two = second;
	while (first->next != NULL && second->next != NULL) {
		first->data = first->data + second->data;
		second->data = first->data;
		if (first->data > 9) {
			first->data -= 10;
			(first->next)->data += 1;
		}
		first = first->next;
		second = second->next;
	}
	if (first->next != NULL) {
		first->data = first->data + second->data;
		if (first->data > 9) {
			first->data -= 10;
			(first->next)->data += 1;
		}
		return one;
	} else if (second->next != NULL) {
		second->data = first->data + second->data;
		if (second->data > 9) {
			second->data -= 10;
			(second->next)->data += 1;
		}
		return two;
	} else {
		first->data = first->data + second->data;
		if (first->data > 9) {
			list* newNode = getnode();
			newNode->data = 1;
			newNode->next = NULL;
			first->data -= 10;
			first->next = newNode;
		}
		return one;
	}
	return NULL;
}