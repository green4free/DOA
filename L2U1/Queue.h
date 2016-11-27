#ifndef QUEUE_H
#define QUEUE_H

typedef int Data;

/* 1. V�lj implementation. *****************************/
/*    Avkommentera exakt en av dessa tv� rader.        */
#define QUEUE_LIST_IMP // Avkommentera denna rad f�r att implementera k�n som en l�nkad lista
//#define QUEUE_ARRAY_IMP // Avkommentera denna rad f�r att implementera k�n som en array


/* 2A. Om k�n implementeras som en l�nkad lista *************************/
#ifdef QUEUE_LIST_IMP
#include "list.h"    // Er lista inkluderas
typedef List Queue;  // Ordet 'Queue' kommer att vara er listtyp
#else



/* 2B. Om k�n implementeras som en array (cirkul�r k�) ********************/
#ifdef QUEUE_ARRAY_IMP
#define MAXLENGTH 20
struct arrayQueue
{
	Data data[MAXLENGTH];  // Detta �r arrayen av element
	/* 2B. L�gg till fler struct-medlemmar om det beh�vs */
};
typedef struct arrayQueue Queue; // Ordet 'Queue' kommer att vara denna struct-typ



/* Ignorera detta (men ta inte bort det) *************************************/
#else
typedef int Queue; // Anv�nds ej
#endif
#endif
/*****************************************************************************/


/* 3. Interface **************************************************************/
/* Detta f�r inte �ndras p� n�got vis. Typen 'Queue' kommer att bero p� vilken */
/* Implementation ni valt.                                                     */

// Skapar en ny tom k�
Queue initializeQueue(void);

// Returnerar 1 om k�n �r tom, 0 annars
int queueIsEmpty(const Queue queue);

// Returnerar 1 om k�n �r full, 0 annars
int queueIsFull(const Queue queue);

// L�gger ett nytt element sist i k�n
void enqueue(Queue* queue, const Data data);

// Tar bort elementet som �r f�rst i k�n
void dequeue(Queue* queue);

// Returnerar elementet som �r f�rst i k�n
Data peekQueue(const Queue queue);


#endif // Ska vara sist
