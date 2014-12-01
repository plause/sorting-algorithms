#include "sort.h"

void sort(int size, int *array)
{
  int i, j, k, v;

  for (i = size / 2; i != 0; i /= 2)
    for (j = i; j < size; j++, array[k + i] = v)
      for (k = j - i, v = array[j]; k >=0 && v < array[k]; k -= i)
        array[i + k] = array[k];
}
