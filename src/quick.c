#include <stdlib.h>
#include "sort.h"

void sort(int size, int *array)
{
	if (size < 2)
		return;

	int pivot = array[size / 2]; // pick the midian value as pivot
	int i, v, l = 0, e = 0, g = 0;
	int *ll = calloc(size, sizeof(int)); // the less array
	int *ee = calloc(size, sizeof(int)); // the equal array
	int *gg = calloc(size, sizeof(int)); // the greater array

	for (i = 0; i < size; i++) {
		v = array[i];

		if (v < pivot)
			ll[l++] = v;
		else if (v == pivot)
			ee[e++] = v;
		else
			gg[g++] = v;
	}

	for (i = 0; i < l; i++)
		array[i] = ll[i];

	for (i = 0; i < e; i++)
		array[i + l] = ee[i];

	for (i = 0; i < g; i++)
		array[i + l + e] = gg[i];

	free(ll);
	free(ee);
	free(gg);

	sort(l, array);
	sort(g, array + l + e);
}
