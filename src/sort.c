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

static void print(char *label, int size, int *array)
{
  int i = 0;

  fprintf(stdout, "%s", label);

  for (i = 0; i < size; i++)
    fprintf(stdout, " %02d", array[i]);

  fprintf(stdout, "\n");
}

int main(int argc, char **argv)
{
  int size = 5;
  int *array = init(size);

  print("before sort:\n", size, array);
  sort(size, array);
  print("after sort:\n", size, array);

  return 0;
}
