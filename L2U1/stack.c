#include "stack.h"
#include<assert.h>


Stack initializeStack(void)
{
	Stack newStack;
	newStack.length = 0;
	return newStack;
}

int stackIsEmpty(const Stack stack)
{
	if(stack.length) return 0;
	return 1;
}

int stackIsFull(const Stack stack)
{
	if(stack.length == MAXLENGTH) return 1;
	return 0;
}

void push(Stack* stack, const Data data)
{
	(*stack).elements[(*stack).length] = data;
	(*stack).length++;
}

void pop(Stack* stack)
{
	if(!stackIsEmpty(*stack)) (*stack).length--;
}

Data peekStack(const Stack stack)
{
	return stack.elements[stack.length - 1];
}
