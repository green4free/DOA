#include "dstring.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>


DString dstring_initialize(const char* str)
{
	assert(str != NULL);
	DString newString = malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(newString, str);
	return newString;
}

int dstring_concatenate(DString* destination, DString source)
{
	assert(destination != NULL);
	assert(*destination != NULL);
	assert(source != NULL);
	DString temp = malloc(strlen(*destination) + strlen(source) + 1);
	//*destination = realloc(*destination, strlen(*destination) + strlen(source) + 1);
	if (temp != NULL) {
		strcpy(temp , *destination);
		strcat(temp  , source);
		free(*destination);
		*destination = temp;
		return 1;
	}
		else
		return 0;
}

void dstring_truncate(DString* destination, unsigned int truncatedLength)
{
	 	assert(destination != NULL);
		assert(*destination != NULL);
		if (strlen(*destination) > truncatedLength) {
		*destination = realloc(*destination, truncatedLength + 1);
		*(*destination + truncatedLength) = '\0';
	}
}

void dstring_print(DString str, FILE* textfile)
{
	assert(textfile != NULL);
	assert(str != NULL);
	fputs(str, textfile);
	//fputs("\n", textfile);
}

void dstring_delete(DString* stringToDelete)
{
	assert(stringToDelete != NULL);
	free(*stringToDelete);
	*stringToDelete = NULL;
}
