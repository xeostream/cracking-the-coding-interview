#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct tnode {
	int data;
	struct tnode *left, *right;
} tnode;

tnode *addTree(tnode *, int);
void treeprint(tnode *);
int getHeight(tnode *);
tnode *getmidle(tnode *, int [], int, int);

tnode *root;
int height, max;
main()
{
	int test[SIZE] = {
		1,3,5,7,9,10,11,12,13,14
	};
	int n = 10;
	height = max = 0;
	root = getmidle(root, test, 0, 9);
	getHeight(root);
	printf("max_height= %d\n", max);
	//treeprint(root);
	return 0;
}

tnode *getmidle(tnode *node, int test[], int begin, int end)
{
	if (begin <= end) {
		int temp = (begin + end) / 2;
		node = addTree(node, test[temp]);
		getmidle(node, test, begin, temp-1);
		getmidle(node, test, temp+1, end);
		return node;
	}
	return NULL;
}

tnode *addTree(tnode *node, int data)
{
	if (node == NULL) {
		node = (tnode *)malloc(sizeof(tnode));
		node->data = data;
		node->left = node->right = NULL;
	} else if (node->data > data)
		node->right = addTree(node->right, data);
	else if (node->data <= data)
		node->left = addTree(node->left, data);
	return node;
}

void treeprint(tnode *root)
{
	if (root == NULL) return ;
	printf("%d\n", root->data);
	treeprint(root->left);
	treeprint(root->right);
}

int getHeight(tnode *node)
{
	if (node == NULL) {
		if (height > max)
			max = height;
			return max;
	}
	height++;
	getHeight(node->left);
	getHeight(node->right);
	height--;
}	