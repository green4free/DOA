#include <stdlib.h>
#include "BSTree.h"
#include <math.h>
#include <stdio.h>
// Statiska hj�lpfunktioner /////////////////////////////////////////////////////////////

// Skapar en tr�dnod med det givna datat samt allokerar minne f�r det
static struct treeNode* createNode(int data)
{
	struct treeNode* new = malloc(sizeof(struct treeNode));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void writeSortedToArrayH(int* arr, int* n, const BSTree tree) {
	if (tree->left != NULL) writeSortedToArrayH(arr, n, tree->left);
	arr[*n] = tree->data;
	(*n)++;
	if (tree->right != NULL) writeSortedToArrayH(arr, n, tree->right);
}

// Returnerar en dynamiskt allokerad array som inneh�ller tr�dets data sorterat
static int* writeSortedToArray(const BSTree tree)
{
int* sortedNodes = malloc(sizeof(int) * numberOfNodes(tree));
int n = 0;
if (tree != NULL) writeSortedToArrayH(sortedNodes, &n, tree);
return sortedNodes;
}




static BSTree buildTreeSortedFromArrayH(const int arr[], int start, int end) {
  if (start > end) return NULL;
  int mid = start + (end - start) / 2;
  BSTree tree =  createNode(arr[mid]);
  tree->left = buildTreeSortedFromArrayH(arr, start, mid-1);
  tree->right = buildTreeSortedFromArrayH(arr, mid+1, end);
  return tree;
}

void buildTreeSortedFromArray(BSTree* tree, const int arr[], int size)
{
	*tree = buildTreeSortedFromArrayH(arr, 0, size-1);
}
// Implementation av tr�det ////////////////////////////////////////////////////////

BSTree emptyTree(void)
{
	return NULL; // Denna funktion �r klar
}

int isEmpty(const BSTree tree)
{
	return !tree;
}

void insertSorted(BSTree* tree, int data)
{
	if(isEmpty(*tree)) {
		*tree = createNode(data);
	}
	else{
		if (data < (*tree)->data){
			insertSorted(&((*tree)->left), data);
		}
		else if(data > (*tree)->data){
			insertSorted(&((*tree)->right), data);
		}
	}
}

void printPreorder(const BSTree tree)
{
	if(!isEmpty(tree)){
		printf(" %d ", tree->data);
		if (tree->left != NULL) printPreorder(tree->left);
		if (tree->right != NULL) printPreorder(tree->right);
	}
}

void printInorder(const BSTree tree)
{
	if(!isEmpty(tree)){
		if (tree->left != NULL) printInorder(tree->left);
		printf(" %d ", tree->data);
		if (tree->right != NULL) printInorder(tree->right);
	}
}

void printPostorder(const BSTree tree)
{
	if(!isEmpty(tree)){
		if (tree->left != NULL) printPostorder(tree->left);
		if (tree->right != NULL) printPostorder(tree->right);
		printf(" %d ", tree->data);
	}
}

int find(const BSTree tree, int data)
{
	if(isEmpty(tree)) return 0;
	if(data == tree->data) return 1;
	if(data < tree->data) return find(tree->left, data);
	if(data > tree->data) return find(tree->right, data);
}

static BSTree removeElementH(BSTree tree, int data)
{
    if (tree == NULL) return tree;

    if (data < tree->data)
        tree->left = removeElementH(tree->left, data);

    else if (data > tree->data)
        tree->right = removeElementH(tree->right, data);

    else
    {
        if (tree->left == NULL)
        {
            BSTree temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL)
        {
            BSTree temp = tree->left;
            free(tree);
            return temp;
        }

				BSTree temp;
				for(temp = tree->right; temp->left != NULL; temp = temp->left);

        tree->data = temp->data;
        tree->right = removeElementH(tree->right, temp->data);
    }
    return tree;
}

void removeElement(BSTree* tree, int data)
{
	*tree = removeElementH(*tree, data);
	}

static void numberOfNodesH(int* n, const BSTree tree) {
	if (tree->left != NULL) numberOfNodesH(n, tree->left);
	(*n)++;
	if (tree->right != NULL) numberOfNodesH(n, tree->right);
}

int numberOfNodes(const BSTree tree)
{
	int n = 0;
	if (tree != NULL) numberOfNodesH(&n, tree);
	return n;
}

int depth(const BSTree tree)
{
	if(!tree) return 0;
	int leftDepth = depth(tree->left);
	int rightDepth = depth(tree->right);
	return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}


int minDepth(const BSTree tree)
{
	return ceil(log((double)(numberOfNodes(tree) + 1))/log(2.0));
}

void balanceTree(BSTree* tree)
{
	// F�rslag p� algoritm:
	// - �verf�r tr�det till en dynamiskt allokerad array med writeSortedToArray()
	// - t�m tr�det med freeTree()
	// - bygg upp tr�det rekursivt fr�n arrayen med buildTreeSortedFromArray()
	// - frig�r minne f�r den dynamiskt allokerade arrayen
	if(depth(*tree) != minDepth(*tree)) {
		int n = numberOfNodes(*tree);
		int* arr = writeSortedToArray(*tree);
		freeTree(tree);
		buildTreeSortedFromArray(tree, arr, n);
		free(arr);
	}
	// Post-conditions:
	// - tree har lika m�nga noder som tidigare
	// - djupet f�r tr�det �r samma som minimumdjupet f�r tr�det
}

static void freeTreeH(BSTree tree)
{
	if(!isEmpty(tree)){
		if (tree->left != NULL) {
			freeTreeH(tree->left);
			tree->left = NULL;
		}
		if (tree->right != NULL) {
		 freeTreeH(tree->right);
		 tree->right = NULL;
	 }
	 free(tree);
	}
}

void freeTree(BSTree* tree) {
	freeTreeH(*tree);
	*tree = NULL;
}
