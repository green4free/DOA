#include "list.h"

/* Skriv era funktionsimplementationer f�r interfacet till er l�nkade lista h�r
   Det g�r ocks� bra att skriva statiska hj�lpfunktioner i denna fil            */
   int findn(DATA num)
   {
       int n = 0;
       while(num) {
           num /= 10;
           n++;
       }
       return n;
   }

node* pointerToIndex(List root, int index) {
  node* temp = root;
  for(int i = 0; i < index; i++){
    temp = temp->next;
    //assert(temp->next != NULL || i == index);
  }
  return temp;
}

node* createNode(const DATA data) {
  node* newNode = malloc(sizeof(node));
  newNode->value = data;
  newNode->next = NULL;
  return newNode;
}

List createList(void) {
  List newList = NULL;
  return newList;
}

void addToEnd(List* root, node* newNode) {
  if (*root == NULL) {
      addToBeginning(root, newNode);
  }
  else {
    node* temp;
    for(temp = *root; temp->next != NULL; temp = temp->next);
    temp->next = newNode;
  }
}

void addToBeginning(List* root, node* newNode) {
  node* temp = *root;
  *root = newNode;
  newNode->next = temp;
}

void addAtIndex(List* root, const int index, node* newNode){
  if(index == 0) {
    addToBeginning(root, newNode);
  }
  else {
    node* temp = pointerToIndex(*root, index - 1);
    node* save = temp->next;
    temp->next = newNode;
    newNode->next = save;
  }
}

void printList(const List root,FILE * fp) {
  node* temp;
  char* str = malloc(sizeof(char));
  int n;
  for(temp = root; temp != NULL; temp = temp->next){
    n = findn(temp->value);
    str = realloc(str,(n + 2 )* sizeof(char));
    sprintf(str, "%d", temp->value);
    str[n] = '\n';
    str[n+1] = '\0';
    fputs(str, fp);
  }
  free(str);
}

void deleteFirst(List* root) {
  assert(*root != NULL);
  node* temp = *root;
  *root = temp->next;
  free(temp);
}

void deleteAtIndex(List* root, const int index) {
  if(index == 0) {
    deleteFirst(root);
  }
  else {
    node* temp = pointerToIndex(*root, index - 1);
    node* del = temp->next;
    temp->next = temp->next->next;
    free(del);
  }
}

void deleteLast(List* root) {
  assert(*root != NULL);
  if((*root)->next == NULL) {
    deleteFirst(root);
  }
  else {
    node* temp;
    for(temp = *root; temp->next->next != NULL; temp = temp->next);
    free(temp->next);
    temp->next = NULL;
  }
}

int isListEmpty(List root) {
  if(root == NULL) return TRUE;
  return FALSE;
}

int isElementInList(List root, DATA element) {
  if (root == NULL) return FALSE;
  node* temp;
  for(temp = root; temp->next != NULL; temp = temp->next){
    if(temp->value == element) return TRUE;
  }
    if(temp->value == element) return TRUE;
  return FALSE;
}

void deleteList(List* root) {
  assert(*root != NULL);
  node *a, *b;
  for(a = *root; a->next != NULL; a = b){
    b = a->next;
    free(a);
  }
  *root = NULL;
}

int numberOfElementsInList(List root) {
  assert(root != NULL);
  if (root == NULL) return 0;
  node* temp;
  int i = 0;
  for(temp = root; temp->next != NULL; temp = temp->next){
    i++;
  }
  return i + 1;
}

void swap(node* preB, node* preA, node* B, node* A){
  if (preA) preA->next = B;
  if (preB) preB->next = A;

  node* temp = A->next;
  A->next = B->next;
  B->next = temp;
}

void swapByIndex(List* root, int a, int b) {
  if (a != b) {
    node* preB;
    node* preA;
    node* B;
    node* A;
    if (a == 0) {
      preB = pointerToIndex(*root, b - 1);
      preA = NULL;
      B = preB->next;
      A = *root;
      *root = B;
    }
    else if (b == 0) {
      preA = pointerToIndex(*root, a - 1);
      preB = NULL;
      A = preA->next;
      B = *root;
      *root = A;
    }
    else {
      preA = pointerToIndex(*root, a - 1);
      preB = pointerToIndex(*root, b - 1);
      A = preA->next;
      B = preB->next;
    }
    swap(preB, preA, B, A);
  }
}

DATA getValueOfFirst(List root) {
  assert(root != NULL);
  return root->value;
}

DATA getValueOfLast(List root) {
  assert(root != NULL);
  node* temp;
  for(temp = root; temp->next != NULL; temp = temp->next);
  return temp->value;
}

DATA getValueAtIndex(List root, const int index) {
  assert(root != NULL);
  return pointerToIndex(root, index)->value;
}

void deleteByValue(List* root, const DATA data) {
  assert(*root != NULL);
  if(isElementInList(*root, data)){
  if((*root)->value == data) {
    deleteFirst(root);
  }
  else {
    node* temp;
    for(temp = *root; temp->next->value != data; temp = temp->next);
    node* save = temp->next->next;
    free(temp->next);
    temp->next = save;
  }
}
}
