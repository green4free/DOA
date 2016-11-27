#include <assert.h>
#include "BSTree.h"
#include <stdio.h>

void testTree(void)
{
	BSTree tree = emptyTree();
	assert(isEmpty(tree));

	// S�tt in 7 element i tr�det
	int arr[7] = {5,10,1,3,7,18,20}, i;
	for (i = 0; i < 7; i++)
	{
		insertSorted(&tree, arr[i]);
	}

	for (i = 0; i < 7; i++)
	{
		// Verifiera att alla element finns i tr�det
		assert(find(tree, arr[i]));
	}

	assert(numberOfNodes(tree) == 7);
	assert(depth(tree) == 4); // Om vi s�tter in noderna i denna ordning blir djupet 4
	assert(minDepth(tree) == 3); // Med 7 noder �r minimidjupet 3

	removeElement(&tree, 18); // Tar bort ett element med ett barn
	removeElement(&tree, 5); // Tar bort ett element med tv� barn
	assert(numberOfNodes(tree) == 5); // Tv� noder har blivit borttagna

	// Verifiera att talen blivit borttagna
	assert(!find(tree, 18));
	assert(!find(tree, 5));

	// Addera 10 element s� att tr�det blir obalancerat
	for (i = 0; i < 10; i++)
		insertSorted(&tree, i+100);

	assert(numberOfNodes(tree) == 10 + 5);

	balanceTree(&tree);
	assert(numberOfNodes(tree) == 10 + 5); // Verifiera att antalet noder �r detsamma
	assert(depth(tree) == minDepth(tree)); // Verifiera att tr�det �r balancerat

	// T�m tr�det och kontrollera att det �r tomt
	freeTree(&tree);
	assert(isEmpty(tree));
	assert(numberOfNodes(tree) == 0);
	assert(depth(tree) == 0);
}


void menuTree(void)
{
	int inData;
	BSTree tree = emptyTree();
	printf("0: balanceTree, 1: numberOfNodes, 2: insertSorted, 3: find, 4: removeElement, 5: depth, 6: print\n");
	for(;;) {
			switch (getchar()) {
				case '0':
				balanceTree(&tree);
				break;

				case '1':
				printf("%d\n", numberOfNodes(tree));
				break;

				case '2':
				scanf(" %d", &inData);
				insertSorted(&tree, inData);
				break;

				case '3':
				scanf(" %d", &inData);
				printf("%d\n", find(tree, inData));
				break;

				case '4':
				scanf(" %d", &inData);
				removeElement(&tree, inData);
				break;

				case '5':
				printf("Depth %d, Min depth %d\n", depth(tree), minDepth(tree));
				break;

				case '6':
				printPreorder(tree);
				printf("\n");
				printInorder(tree);
				printf("\n");
				printPostorder(tree);
				printf("\n");
				break;
			}
			printf("\n");
	}
}


int main(void)
{
testTree();
menuTree();
}
