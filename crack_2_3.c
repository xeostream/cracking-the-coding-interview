#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list *next;
}list;

list *init(int *, int);
void print(list *);
list *getnode(void);
list *deletenode(list *);

main()
{
	int n = 10, position = 3;
	int test[] = {3,2,1,3,5,6,2,6,3,1};
	list *head = init(test, n);
	list *nod = head;
	print(head);
	for (; position > 0; position--)
		nod = nod->next;
	nod = deletenode(nod);
	if (nod)
		print(head);
	return 0;
}

list *deletenode(list *nod)
{
	if (nod == NULL || nod->next == NULL)
		return NULL;
	else {
		list *temp = nod->next;
		nod->data = temp->data;
		nod->next = temp->next;
		temp = NULL;
		return nod;
	}	
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

void print(list *head)
{
	while (head) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

list *getnode()
{
	return (list *)malloc(sizeof(list));
}