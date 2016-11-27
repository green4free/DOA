#include <assert.h>
#include <string.h>

#include "dstring.h"

/* Detta program testar funktionaliteten f�r ADTn DString */
int main(void)
{
	DString str1, str2;
	str1 = dstring_initialize("Department of ");
	str2 = dstring_initialize("Redundancy ");
	dstring_concatenate(&str1, str2); // Sl�r ihop str1 och str2 och l�gger resultatet i str1. Str1 inneh�ller nu "Department of Redundancy"

	/* Om n�gon av dessa misslyckas s� �r det n�got fel p� er implementation
	   Anv�nd debuggern f�r att ta reda p� vad */

	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(strlen(str2) == 11);
	assert(strlen(str1) == 25); // Den sammanslagna str�ngen ska ha l�ngden 25

	/* F�ljande ska skriva ut "Department of Redundancy Department" p� sk�rmen
	   stdout �r en textfil som representerar konsollf�nstret */

	dstring_print(str1, stdout);	// Skriver ut "Department of Redundancy"
	dstring_truncate(&str1, 10);	// F�rkortar str1 s� att den bara inneh�ller de 10 f�rsta tecknen i str�ngen, dvs "Department"
	dstring_print(str1, stdout);	// Skriver ut "Department"

	/* Frig�r det dynamiskt allokerade minnet f�r str�ngarna */
	dstring_delete(&str1);
	dstring_delete(&str2);

	/* Se till att str�ngarna blivit nollst�llda */
	assert(str1 == NULL);
	assert(str2 == NULL);
	return 0;
}
