#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Bucket.h"
#include "list.h" // Avkommentera denna rad ifall du vill implementera Hashtabellen med l�nkade listor

typedef struct
{
	// Steg 1: Avkommentera exakt en av dessa rader

	//struct Bucket* table; // Avkommentera denna ifall ni vill implementera Hashtabellen med �ppen adresering
	List* table;   // Avkommentera denna ifall ni vill implemenetera Hashtabellen som en array l�nkade listor

	unsigned int size; // Storleken p� Hashtabellen
} HashTable;


// Interface //////////////////////////////////////////////////////////////////////////

HashTable createHashTable(unsigned int size);

// S�tter in paret {key,data} i Hashtabellen, om en nyckel redan finns ska v�rdet modifieras
void insertElement(HashTable* htable, const Key key, const Value value);

// Tar bort datat med nyckel "key"
void deleteElement(HashTable* htable, const Key key);

// Returnerar en pekare till v�rdet som key �r associerat med eller NULL om ingen s�dan nyckel finns
const Value* lookup(const HashTable* htable, const Key key);

// T�mmer Hashtabellen
void freeHashTable(HashTable* htable);

// Ger storleken av Hashtabellen
unsigned int getSize(const HashTable* htable);

// Denna f�r att ni enkelt ska kunna visualisera en Hashtabell
void printHashTable(const HashTable* htable);

#endif
