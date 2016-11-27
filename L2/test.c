#include "list.h"
#include "Queue.h"
#include "stack.h"
#include "Set.h"
#include <assert.h>
#include <stdio.h>

void testQueue(void);
void testStack(void);
void testSet(void);
void listMenu(void);

int main(void)
{
	/* Uppgift 2.1: Avkommentera raden nedan n�r stacken �r klar att testas */
testStack();
	/* Uppgift 2.2: Avkommentera raden nedan n�r k�n �r klar att testas */
	testQueue();

	/* Uppgift 2.3: Avkommentera raden nedan n�r set �r klar att testas */
		testSet();

	// Uppgift 2: kommentera bort listMenu() n�r ni vill testa ADT:erna */
	listMenu();
return 0;
}


void help(void) {
  printf("0 - Add element to end\n1 - Add element to start\n2 - Add element by index\n3 - Delete first element\n4 - Delete last element\n5 - Delete element by index\n6 - Delete list\n7 - Is list empty\n8 - Is element in list\n9 - Number of elements in list\n10 - Swap elements by index\n11 - Print first element\n12 - Print last element\n13 - Print element by index\n14 - Print list\n15 - Exit\n");
}

void menu(int choice, List* a){
  int temp;
  int temp1, temp2;
  printf("OK.\n");
  switch(choice) {
    case 0:
      //add element to end.
      scanf(" %d", &temp);
      addToEnd(a,createNode(temp));
      break;

      case 1:
        //add element to start.
        scanf(" %d", &temp);
        addToBeginning(a,createNode(temp));
        break;

        case 2:
          //add element to index.
          scanf(" %d", &temp);
          scanf(" %d", &temp1);
          addAtIndex(a, temp1, createNode(temp));
          break;
        case 3:
            //Delete first
            deleteFirst(a);
            break;

          case 4:
              //Delete last
              deleteLast(a);
              break;

            case 5:
                //Delete element by index
                scanf(" %d", &temp1);
                deleteAtIndex(a, temp1);
                break;
                case 6:
                    //Delete list.
                    deleteList(a);
                    break;

                  case 7:
                      //Is list empty
                      if(isListEmpty(*a)){
                        printf("Yes\n");
                      }
                      else {
                        printf("No\n");
                      }
                      break;

                    case 8:
                        //add element to index.
                        scanf(" %d", &temp1);
                        if(isElementInList(*a, temp1)) {
                          printf("Yes\n");
                        }
                        else {
                          printf("No\n");
                        }
                        break;

                        case 9:
                        printf("Number of items in list: %d\n", numberOfElementsInList(*a));
                        break;

                        case 10:
                        scanf(" %d", &temp1);
                        scanf(" %d", &temp2);
                        swapByIndex(a, temp1, temp2);
                        break;

                        case 11:
                        printf("%d\n",getValueOfFirst(*a));
                        break;

                        case 12:
                        printf("%d\n",getValueOfLast(*a));
                        break;

                        case 13:
                        scanf(" %d", &temp1);
                        printf("%d\n",getValueAtIndex(*a, temp1));
                        break;

                        case 14:
                        printList(*a, stdout);
                        break;

                        case 15:
                          assert(FALSE);
                          break;

                        default:
                        help();
                        break;
  }
	printList(*a, stdout);
}


void listMenu(void)
{
	List a = createList();
  help();
  int temp;
  while (TRUE) {
    scanf(" %d", &temp);
    menu( temp, &a);
  }
}

void testQueue(void)
{
	Queue queue = initializeQueue();

	// K�n ska vara tom och inte full
	assert(queueIsEmpty(queue));
	assert(!queueIsFull(queue));

	int i;
	// Fyller k�n med 1 2 3 4 5 6 7 8 9 10
	for (i = 1; i <= 10; i++)
		enqueue(&queue, i);

	assert(!queueIsEmpty(queue));
	assert(peekQueue(queue) == 1);	// 1 ska st� f�rst i k�n

	for (i = 0; i < 5; i++)
		dequeue(&queue);	// Ta bort de fem f�rsta i k�n (b�r vara 1,2,3,4 och 5)

	assert(!queueIsEmpty(queue));
	assert(peekQueue(queue) == 6);	// 6 b�r allts� st� f�rst i k�n nu

	enqueue(&queue, 11);
	assert(peekQueue(queue) == 6);	// 6 b�r fortfarande vara f�rst i k�n

	// Ta bort alla element
	for (i = 0; i < 6; i++) // K�n ska nu inneh�lla 6 element totalt
		dequeue(&queue);

	// �terigen ska k�n vara tom och inte full
	assert(queueIsEmpty(queue));
	assert(!queueIsFull(queue));

	// L�gg till och ta bort 100 element
	for (i = 0; i < 100; i++)
	{
		enqueue(&queue, i);
		assert(peekQueue(queue) == i);
		dequeue(&queue);
		assert(queueIsEmpty(queue));
	}
}

void testStack(void)
{
	Stack stack = initializeStack();

	// Stacken ska vara tom och inte full
	assert(stackIsEmpty(stack));
	assert(!stackIsFull(stack));

	int i;
	// Fyller stacken med 1 2 3 4 5 6 7 8 9 10
	for (i = 1; i <= 10; i++)
		push(&stack, i);

	assert(!stackIsEmpty(stack));
	assert(peekStack(stack) == 10);	// �versta elementet b�r vara 10

	for (i = 0; i < 5; i++)
		pop(&stack);	// Ta bort de fem �versta i stacken (10, 9, 8, 7 och 6)

	assert(!stackIsEmpty(stack));
	assert(peekStack(stack) == 5);	// 5 b�r allts� vara �verst p� stacken nu

	push(&stack, 0); // L�gg 0 �verst p� stacken
	assert(peekStack(stack) == 0);
	pop(&stack);
	assert(peekStack(stack) == 5); // 5 �r n�st �verst

	// Ta bort de kvarvarande elementen
	for (i = 0; i < 5; i++)
		pop(&stack);

	// �terigen ska k�n vara tom och inte full
	assert(stackIsEmpty(stack));
	assert(!stackIsFull(stack));
}

void testSet(void)
{
	Set set = initializeSet();
	int i;

	for (i = 1; i <= 10; i++)
		assert(!isInSet(set, i)); // Inget element f�r finnas i settet

	for (i = 1; i <= 10; i++)
		if (i % 2 == 0)
			addToSet(&set, i);	// L�gg till alla j�mna tal mellan 1 och 10 (dvs 2,4,6,8,10)

	for (i = 1; i <= 10; i++)
		if (i % 3 == 0)
			removeFromSet(&set, i); // Ta bort alla tal som �r delbara med 3 fr�n set (dvs tar bort 6, kvar ska 2,4,8,10 vara)

	for (i = 1; i <= 10; i++)
		if (i % 2 == 0 && i % 3 != 0)
		{
			assert(isInSet(set, i)); // Talet ska finnas i set om det �r j�mnt men inte delbart med tre
		}
		else
		{
			assert(!isInSet(set, i)); // Annars ska det inte finnas
		}
}
