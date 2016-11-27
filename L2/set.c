#include "Set.h"
#include <assert.h>


Set initializeSet(void)
{
	return createList();
}

void addToSet(Set* set, const Data element)
{
	if(!isElementInList(*set, element)){
		addToBeginning(set, createNode(element));
	}
}

void removeFromSet(Set* set, const Data element)
{
	deleteByValue(set, element);
}

int isSetFull(const Set set)
{
	return 0;
}

int isInSet(const Set set, const Data element)
{
	return isElementInList(set, element);
}
