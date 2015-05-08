#include "sort.h"

void sort(int size, int *array)
{
	int i, j;

	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
			if (array[i] > array[j])
				swap(array + i, array + j);
}
