/* Laboration 2 - Datastrukturer och Algoritmer */
/* L�nkad lista */

#ifndef LIST_H
#define LIST_H

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Bucket.h"

typedef struct Bucket DATA;

/* 1. Struct-definitioner ********************************/
/*                                                       */
/* L�gg era struct-definitioner nedan                    */
/* Ni kan g�ra en enkell�nkad eller dubbell�nkad         */
/* lista. Ni f�r ocks� v�lja hur ni vill representera    */
/* listan (nodpekare eller strukt).                      */
/*********************************************************/

typedef struct NODE {
  DATA value;
  struct NODE *next;
}node;

typedef node* List;
/* 2. Typdefinition **************************************/
/* Ers�tt ordet 'int' nedan med den typ ni valt          */
/* T.ex:											     */
/* typedef struct node* List;                            */
/* eller											     */
/* typedef struct list List;                             */
/* *******************************************************/

// Obs: �ndra ej namnet "List", det kommer att anv�ndas i kommande la


/* 3. Interface ****************************************************/
/* H�r l�gger ni era funktionsdeklarationer f�r er l�nkade lista   */
/* L�s labbinstruktioner f�r vilka som ska vara med                */
/*																   */
/* OBS:															   */
/* ALLA funktioner i interfacet m�ste returnera eller ta ett       */
/* argument av typen List eller List*                              */
/* *****************************************************************/
node* createNode(const DATA data);
List createList(void);
void addToEnd(List *root, node* newNode);
void addToBeginning(List *root, node* newNode);
void addAtIndex(List* root, const int index, node* newNode);
void deleteFirst(List* root);
void deleteAtIndex(List* root, const int index);
void deleteLast(List* root);
int isListEmpty(List root);
int isElementInList(List root, Key element);
void deleteList(List* root);
int numberOfElementsInList(List root);
void swapByIndex(List* root, int a, int b);
DATA getValueOfFirst(List root);
DATA getValueOfLast(List root);
DATA getValueAtIndex(List root, const int index);
void deleteByValue(List* root, const Key data);
Value* getByKey(List* root, const Key data);

#endif // Ska vara sist
