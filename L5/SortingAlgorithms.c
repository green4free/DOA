#define _CRT_SECURE_NO_WARNINGS
#include "SortingAlgorithms.h"
#include "Statistics.h"
#include "Array.h"
#include <assert.h>
#include <string.h>


int isImplemented(SortingAlgorithm algorithm)
{
	switch (algorithm)
	{
	case BUBBLE_SORT:
	case INSERTION_SORT:
	case SELECTION_SORT:
	case QUICK_SORT:
//	case MERGE_SORT:
		return 1;
	default:
		return 0;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Era algoritmer h�r:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//Bubble Sort
////////////////////////////////////////////////////////////////////////////////////////////////////

static void bubbleSort(ElementType* arrayToSort, size_t n, Statistics* statistics)
{
	int i, j;
  for (i = 0 ; lessThan(i , ( n - 1 ), statistics); i++)
  {
    for (j = 0 ; lessThan(j, n - i - 1, statistics); j++)
    {
      if (greaterThan(arrayToSort[j], arrayToSort[j+1], statistics)) /* For decreasing order use < */
      {
				swapElements(arrayToSort + j, arrayToSort + j + 1, statistics);
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Insertion Sort
////////////////////////////////////////////////////////////////////////////////////////////////////

static void insertionSort(ElementType* arrayToSort, size_t n, Statistics* statistics)
{
	int i, j;
	for (i = 1 ; lessThanOrEqualTo(i, n - 1, statistics); i++) {
	j = i;

	while ( greaterThan(j, 0, statistics) && lessThan(arrayToSort[j], arrayToSort[j-1], statistics)) {
		swapElements(arrayToSort + j, arrayToSort + j - 1, statistics);
		j--;
	}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Selection Sort
////////////////////////////////////////////////////////////////////////////////////////////////////

static void selectionSort(ElementType* arrayToSort, size_t n, Statistics* statistics)
{
	int i, j, position;
	for ( i = 0 ; lessThan(i, ( n - 1 ), statistics) ; i++ )
	   {
	      position = i;

	      for ( j = i + 1 ; lessThan(j, n, statistics) ; j++ )
	      {
	         if ( greaterThan(arrayToSort[position], arrayToSort[j], statistics) )
	            position = j;
	      }
	      if ( !equalTo(position, i, statistics) )
	      {
					swapElements(arrayToSort + i, arrayToSort + position, statistics);
	      }
	   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Merge Sort
////////////////////////////////////////////////////////////////////////////////////////////////////

static void mergeSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Quick Sort
////////////////////////////////////////////////////////////////////////////////////////////////////

static int quickSortPartition(ElementType* arrayToSort, int low, int high, Statistics* statistics)
{
	int pivot = arrayToSort[low + (high - low)/2];
	int pivot_point = low + (high - low)/2;
	int leftPlace = low;
	int i;
	for(i = low; lessThan(i, high, statistics); i++){
		if(lessThan(arrayToSort[i], pivot, statistics)){
			swapElements(arrayToSort + i, arrayToSort + leftPlace, statistics);
			leftPlace++;
		}
	}
	swapElements(&pivot, arrayToSort + leftPlace, statistics);
	return leftPlace;
}

static void recursivQuickSort(ElementType* arrayToSort, int low, int high, Statistics* statistics)
{
	if (lessThan(low, high, statistics))
	{
		int pivot = quickSortPartition(arrayToSort, low, high, statistics);
		recursivQuickSort(arrayToSort, low, pivot, statistics);
		recursivQuickSort(arrayToSort, pivot + 1, high, statistics);
	}
}

static void quickSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
	recursivQuickSort(arrayToSort, 0, size, statistics);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//Radix Sort
////////////////////////////////////////////////////////////////////////////////////////////////////

static void radixSort(ElementType* arrayToSort, size_t n, Statistics* statistics)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


char* getAlgorithmName(SortingAlgorithm algorithm)
{
	/* �r inte str�ngen vi allokerar lokal f�r funktionen?
	   Nej, inte i detta fall. Str�ngkonstanter �r ett speciallfall i C */
	switch (algorithm)
	{
	case BUBBLE_SORT:	 return "  Bubble sort ";
	case SELECTION_SORT: return "Selection sort";
	case INSERTION_SORT: return "Insertion sort";
	case MERGE_SORT:	 return "  Merge sort  ";
	case QUICK_SORT:	 return "  Quick sort  ";
	default:
		assert(0 && "Ogiltig algoritm!");
		return "";
	}
}

// Sorterar 'arrayToSort' med 'algorithmToUse'. Statistik f�r antal byten och j�mf�relser hamnar i *statistics
static void sortArray(ElementType* arrayToSort, size_t size, SortingAlgorithm algorithmToUse, Statistics* statistics)
{
	if(statistics != NULL)
		resetStatistics(statistics);

	switch (algorithmToUse)
	{
	case BUBBLE_SORT:	 bubbleSort(arrayToSort, size, statistics); break;
	case SELECTION_SORT: selectionSort(arrayToSort, size, statistics); break;
	case INSERTION_SORT: insertionSort(arrayToSort, size, statistics); break;
	case MERGE_SORT:	 mergeSort(arrayToSort, size, statistics); break;
	case QUICK_SORT:	 quickSort(arrayToSort, size, statistics); break;
	default:
		assert(0 && "Ogiltig algoritm!");
	}
}

// F�rbereder arrayer f�r sortering genom att allokera minne f�r dem, samt intialisera dem
static void prepareArrays(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], const unsigned int sizes[])
{
	assert(isImplemented(algorithm));

	int i;
	int totalArraySize;

	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		totalArraySize = sizeof(ElementType)*sizes[i];
		sortingArray[i].arrayToSort = malloc(totalArraySize);
		memcpy(sortingArray[i].arrayToSort, arrays[i], totalArraySize);

		sortingArray[i].algorithm = algorithm;
		sortingArray[i].arraySize = sizes[i];
		resetStatistics(&sortingArray[i].statistics);
	}
}

// Sorterar arrayerna
static void sortArrays(SortingArray toBeSorted[])
{
	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		SortingArray* current = &toBeSorted[i];
		sortArray(current->arrayToSort, current->arraySize, current->algorithm, &current->statistics);

		if (!isSorted(current->arrayToSort, current->arraySize))
		{
			printf("Fel! Algoritmen %s har inte sorterat korrekt!\n", getAlgorithmName(current->algorithm));
			printf("Resultatet �r: \n");
			printArray(current->arrayToSort, current->arraySize, stdout);
			assert(0); // Aktiveras alltid
		}
	}
}

void printResult(SortingArray sortedArrays[], FILE* file)
{
	assert(file != NULL);

	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		fprintf(file, "%4d element: ", sortedArrays[i].arraySize);
		printStatistics(&sortedArrays[i].statistics, file);
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
}

void sortAndPrint(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], unsigned int sizes[], FILE* file)
{
	assert(file != NULL);

	prepareArrays(sortingArray, algorithm, arrays, sizes);
	sortArrays(sortingArray);
	printResult(sortingArray, file);
}

void freeArray(SortingArray sortingArray[])
{
	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		if (sortingArray[i].arrayToSort != NULL)
			free(sortingArray[i].arrayToSort);
		sortingArray[i].arrayToSort = NULL;
		sortingArray[i].arraySize = 0;
		resetStatistics(&sortingArray[i].statistics);
	}
}
