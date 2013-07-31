#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list *next;
}list;

list *init(int *, int);
void print(list *);
list *getnode(void);
void clean(list *);

main()
{
	int n = 10;
	int test[] = {3,2,1,3,5,6,2,6,3,1};
	list *first = init(test, n);
	clean(first);
	print(first);
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
void clean(list *head)
{
	list *first = head;
	list *second, *third;
	while (first) {
		second = first->next;
		third = first;
		while (second) {
			if (first->data != second->data) {
				third = second;
				second = third->next;
			} else {
				third->next = second->next;
				second = second->next;
			}
		}
		first = first->next;
	}
}