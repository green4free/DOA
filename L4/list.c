#include "list.h"
#include "Bucket.h"
/* Skriv era funktionsimplementationer f�r interfacet till er l�nkade lista h�r
   Det g�r ocks� bra att skriva statiska hj�lpfunktioner i denna fil            */

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


void deleteFirst(List* root) {
  if(*root != NULL){
  node* temp = *root;
  *root = temp->next;
  free(temp);
}
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
  if(*root != NULL){
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
}

int isListEmpty(List root) {
  if(root == NULL) return TRUE;
  return FALSE;
}

int isElementInList(List root, Key element) {
  if (root == NULL) return FALSE;
  node* temp;
  for(temp = root; temp->next != NULL; temp = temp->next){
    if(temp->value.key == element) return TRUE;
  }
    if(temp->value.key == element) return TRUE;
  return FALSE;
}

void deleteList(List* root) {
  if(*root != NULL){
  node *a, *b;
  for(a = *root; a->next != NULL; a = b){
    b = a->next;
    free(a);
  }
  *root = NULL;
}
}

int numberOfElementsInList(List root) {
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

void deleteByValue(List* root, const Key data) {
  if(*root != NULL){
  if(isElementInList(*root, data)){
  if((*root)->value.key == data) {
    deleteFirst(root);
  }
  else {
    node* temp;
    for(temp = *root; temp->next->value.key != data; temp = temp->next);
    node* save = temp->next->next;
    free(temp->next);
    temp->next = save;
  }
}
}
}

Value* getByKey(List* root, const Key data) {
  if (*root == NULL) return NULL;
  if(isElementInList(*root, data)){
    node* temp;
    for(temp = *root; temp->value.key != data; temp = temp->next);
    return &(temp->value.value);
  }
  return NULL;
}
