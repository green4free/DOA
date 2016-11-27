#include "HashTable.h"
#include "Bucket.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#define UNUSED 0	// Anv�nds f�r att markera en ledig plats i Hashtabellen


/* Denna funktion tar en nyckel och returnerar ett hash-index
dvs ett index till arrayen som �r Hashtabellen */
static int hash(Key key, int tablesize)
{
	return key % tablesize;
}

HashTable createHashTable(unsigned int size)
{
	// Dessa tv� rader �r bara tillf�r att labskelettet ska kompilera. Ta bort dessa n�r du skriver funktionen
	HashTable htable;
	htable.table = calloc(size, sizeof(List));
	htable.size = size;
	return htable;
}

void insertElement(HashTable* htable, const Key key, const Value value)
{
	struct Bucket temp;
	temp.key = key;
	temp.value = value;
	addToEnd(htable->table + hash(key, htable->size), createNode(temp));
}

void deleteElement(HashTable* htable, const Key key)
{
	deleteByValue(htable->table + hash(key, htable->size), key);
}

const Value* lookup(const HashTable* htable, const Key key)
{
	return getByKey(htable->table + hash(key, htable->size), key);
}

unsigned int getSize(const HashTable* htable)
{
	return htable->size;
}

void freeHashTable(HashTable* htable)
{
	int i;
	for (i = 0; i < htable->size; i++) {
		deleteList(htable->table + i);
		//(htable->table)[i] = NULL;
	}
	htable->size = 0;
}

void printHashTable(const HashTable* htable)
{
	int i;
	for (i = 0; i < htable->size; i++) {
		printf("\nHash %d\n", i);
		List temp;
	  for(temp = (htable->table)[i]; temp != NULL; temp = temp->next){
			printf("Key %d\n", temp->value.key);
			printPerson(&(temp->value.value));
	  }
	}
}
