#include <stdlib.h>
#include "sort.h"

static int min(int a, int b)
{
  return a < b ? a : b;
}

static void merge(int lsize, int *larray, int rsize, int *rarray)
{
  int *merged = calloc(lsize + rsize, sizeof(int));
  int i = 0, j = 0, k = 0, n;

  // fill the array with sorted elements
  while (i < lsize && j < rsize)
    merged[k++] = larray[i] < rarray[j] ? larray[i++] : rarray[j++];

  // fill if the left has unchecked elements
  for (n = i; n < lsize; n++)
    merged[k++] = larray[n];

  // fill if the right has unchecked elements
  for (n = j; n < rsize; n++)
    merged[k++] = rarray[n];

  // update the left side of the orignal array
  for (n = 0; n < lsize; n++)
    larray[n] = merged[n];

  // update the right side of the orignal array
  for (n = 0; n < rsize; n++)
    rarray[n] = merged[n + lsize];

  free(merged);
}

void sort(int size, int *array)
{
  if (size == 1)
    return;

  int lsize = size / 2;
  int rsize = size - lsize;

  sort(lsize, array);
  sort(rsize, array + lsize);

  merge(lsize, array, rsize, array + lsize);
}
