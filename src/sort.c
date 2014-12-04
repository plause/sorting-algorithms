#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *a, int *b)
{
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

static int *init(int size)
{
  int i, *array = calloc(size, sizeof(int));

  for (i = 0; i < size; i++)
    array[i] = rand() % 100 + 1;

  return array;
}

void dump(int size, int *array)
{
  if (size < 1)
    return;

  int i;

  for (i = 0; i < size - 1; i++)
    fprintf(stdout, "%02d ", array[i]);

  fprintf(stdout, "%d\n", array[i]);
}

int main(int argc, char **argv)
{
  int size = 5;
  int *array = init(size);

  dump(size, array);
  sort(size, array);
  dump(size, array);

  return 0;
}
