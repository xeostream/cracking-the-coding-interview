#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct tnode {
	int data;
	struct tnode *left, *right;
} tnode;

tnode *addTree(tnode *, int);
void treeprint(tnode *);
void treeprint1(tnode *);
void treeprint2(tnode *);
void getDepth(tnode *, int[]);
int isBalance(int[]);

main()
{
	int items[10] = {  
    1, 3, 5, 7, 9, 8, 6, 4, 2, 0
	};
	int result[10];
	int n = 0;
	tnode *root = NULL;
	for (; n < 10; n++)
		 root = addTree(root, items[n]);
 	getDepth(root, result);
 	if (isBalance(result) == 1)
 		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

tnode *addTree(tnode *root, int data)
{
	if (root == NULL) {
		root = (tnode *)malloc(sizeof(tnode));
		root->data = data;
		root->left = root->right = NULL;
	} else if (root->data < data)
		root->left = addTree(root->left, data);
	else
		root->right = addTree(root->right, data);
	return root;
}

int size = 0, conf = 0;
void getDepth(tnode *root, int result[])
{
	if (root == NULL) return ;
	size++;
	getDepth(root->left, result);
	if (root->left == NULL && root->right == NULL)
		result[conf++] = size;
	getDepth(root->right, result);
	size--;	
}

int isBalance(int result[])
{
	int max, min;
	max = min = result[0];
	for (; conf > 1; conf--) {
		if (max < result[conf-1])
			max = result[conf-1];
		if (min > result[conf-1])
			min = result[conf-1];
	}
	return (max-min) > 1 ? 0 : 1;	
}

void treeprint(tnode *root)
{
	if (root == NULL) return ;
	printf("%d\n", root->data);
	treeprint(root->left);
	treeprint(root->right);
}

void treeprint1(tnode *root)
{
	if (root == NULL) return ;
	treeprint1(root->left);
	printf("%d\n", root->data);
	treeprint1(root->right);
}

void treeprint2(tnode *root)
{
	if (root == NULL) return ;
	treeprint2(root->left);
	treeprint2(root->right);
	printf("%d\n", root->data);
}