#include "sort.h"

void sort(int size, int *array)
{
  int i, n, v;

  for (n = 1; n < size; array[i + 1] = v)
    for (i = n - 1, v = array[n++]; i >= 0 && v < array[i]; i--)
      array[i + 1] = array[i];
}
