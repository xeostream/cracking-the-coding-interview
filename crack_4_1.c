#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct tnode {
	char *word;
	int count;
	struct tnode *left, *right;
} tnode;

tnode *addTree(tnode *, char *);
void treeprint(tnode *);
void treeprint1(tnode *);
void treeprint2(tnode *);

main()
{
	char *items[10] = {  
    "Today","Tomorrow","Tuck","Hello","Mystery","today",  
    "Tuck","Hello","Monday","Monday" 
	};
	int n = 0;
	tnode *root = NULL;
	for (; n < 10; n++)
		 root = addTree(root, items[n]);
 	treeprint(root);
 	printf("------------------------------------\n");
 	treeprint1(root);
 	printf("------------------------------------\n");
 	treeprint2(root);
	return 0;
}

tnode *addTree(tnode *root, char *word)
{
	int cond;
	if (root == NULL) {
		root = (tnode *)malloc(sizeof(tnode));
		root->word = strdup(word);
		root->count = 1;
		root->left = root->right = NULL;
	} else if ((cond = strcmp(word, root->word)) == 0)
		root->count++;
	else if (cond < 0)
		root->left = addTree(root->left, word);
	else
		root->right = addTree(root->right, word);
	return root;
}

void treeprint(tnode *root)
{
	if (root == NULL) return ;
	printf("%s: %d\n", root->word, root->count);
	treeprint(root->left);
	treeprint(root->right);
}

void treeprint1(tnode *root)
{
	if (root == NULL) return ;
	treeprint1(root->left);
	printf("%s: %d\n", root->word, root->count);
	treeprint1(root->right);
}

void treeprint2(tnode *root)
{
	if (root == NULL) return ;
	treeprint2(root->left);
	treeprint2(root->right);
	printf("%s: %d\n", root->word, root->count);
}