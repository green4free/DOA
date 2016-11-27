#ifndef DSTRING_H
#define DSTRING_H
#include <stdio.h>

typedef char* DString;

/* Returnerar en str�ng som inneh�ller samma text som textstr�ngen 'str'. 
  Den returnerade str�ngen �r dynamiskt allokerad (dvs, p� heapen) */
DString dstring_initialize(const char* str);

/* Sl�r ihop originalstr�ngen med source */
int dstring_concatenate(DString* destination, DString source);

/* F�rkortar *destination s� att den inneh�ller h�gst truncatedLength tecken 
  Om 'truncatedLength' �r l�ngre �n str�ngens l�ngd h�nder inget */
void dstring_truncate(DString* destination, unsigned int truncatedLength);

/* Skriver str�ngen till en textfil. 
   Textfilen f�rv�ntas redan vara �ppnad och forts�tter vara �ppnad efter anropet */
void dstring_print(DString stringToPrint, FILE* textfile);

/* Frig�r minnet f�r en dynamisk str�ng och s�tter str�ngen (*stringToDelete) till NULL */
void dstring_delete(DString* stringToDelete);

#endif
