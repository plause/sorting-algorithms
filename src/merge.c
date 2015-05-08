#include <stdlib.h>
#include "sort.h"

static int min(int a, int b)
{
	return a < b ? a : b;
}

static void merge(int lsize, int *larray, int rsize, int *rarray)
{
	int *merged = calloc(lsize + rsize, sizeof(int));
	int i = 0, j = 0, k = 0;

	// fill the array with sorted elements
	while (i < lsize && j < rsize)
		merged[k++] = larray[i] < rarray[j] ? larray[i++] : rarray[j++];

	// fill if the left has unchecked elements
	while (i < lsize)
		merged[k++] = larray[i++];

	// fill if the right has unchecked elements
	while (j < rsize)
		merged[k++] = rarray[j++];

	// update the left side of the orignal array
	for (i = 0; i < lsize; i++)
		larray[i] = merged[i];

	// update the right side of the orignal array
	for (j = 0; j < rsize; j++)
		rarray[j] = merged[j + lsize];

	free(merged);
}

void sort(int size, int *array)
{
	if (size < 2)
		return;

	int lsize = size / 2;
	int rsize = size - lsize;

	sort(lsize, array);
	sort(rsize, array + lsize);

	merge(lsize, array, rsize, array + lsize);
}
