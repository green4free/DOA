#define _CRT_SECURE_NO_WARNINGS // Beh�vs i Visual studio f�r att till�ta vissa funktioner
#include "HashTable.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Person.h"

static int addRandomPersonToTable(HashTable* htable)
{
	Person person = getRandomPerson();
	insertElement(htable, person.personalNumber, person);
	assert(lookup(htable, person.personalNumber)->personalNumber == person.personalNumber); // Se till att personnummret returnerar namnet
	return person.personalNumber;
}

void test(unsigned int tableSize)
{
	assert(tableSize >= 50); // Vi ska l�gga till 50 personer s� vi m�ste minst ha 50 platser

	HashTable htable = createHashTable(tableSize); // Vi g�r storleken till ett primtal
	int personalNumbers[50];
	srand((unsigned int)time(0));

	assert(getSize(&htable) == tableSize);

	int i;
	for (i = 0; i < 50; i++)
	{
		int personalNumber = addRandomPersonToTable(&htable);
		personalNumbers[i] = personalNumber;
	}

	// Ta bort n�gra existerande personer fr�n tabellen
	for (i = 0; i < 10; i++)
	{
		deleteElement(&htable, personalNumbers[i]);
		assert(lookup(&htable, personalNumbers[i]) == NULL); // Det borttagna ska inte l�ngre finnas i tabellen
	}

	// Slutligen l�gger vi till n�gra till
	for (i = 0; i < 10; i++)
	{
		addRandomPersonToTable(&htable);
	}

	printHashTable(&htable);

	freeHashTable(&htable);
	assert(getSize(&htable) == 0);
}


int main(void)
{
	unsigned int size;
	do
	{
		printf("Ange storlek p� Hashtabellen (minst 50): ");
		scanf("%u", &size);
	} while (size < 50);

	test(size);

	// F�r att pausa
	getchar();

	return 0;
}
