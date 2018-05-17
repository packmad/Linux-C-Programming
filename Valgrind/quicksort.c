#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

/* 
 * Study this program!
 * valgrind --tool=callgrind ./quicksort
 * kcachegrind
 */

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1); // index of smaller element

	for (int j = low; j <= high- 1; j++) {
		if (arr[j] <= pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		/* pi is partitioning index, arr[p] is now at right place */
		int pi = partition(arr, low, high);

		// deparately sort elements before partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int arr[] = {1, 7, 13, 2, 14, 16, 4, 8, 15, 9, 20, 10, 6, 5, 17, 3, 12, 18, 11, 19};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printf("Unsorted array: ");
	printArray(arr, n);

	quickSort(arr, 0, n-1);

	printf("Sorted array:   ");
	printArray(arr, n);
	return 0;
}
