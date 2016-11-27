#include <time.h>
#include "list.h"

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
}

int main(void) {
  List a = createList();
  help();
  int temp;
  while (TRUE) {
    scanf(" %d", &temp);
    menu( temp, &a);
  }
  return 0;
}
