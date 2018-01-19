#include "array.h"
#include <stdio.h>
#include <stdlib.h>

void printArray(int * array, int size) {
   for (int i = 0; i < size; i++) {
      printf("[%d] ", array[i]);
   }
   printf("\n");
}

int * copyArray (int * src, int *size) {
   if (!src) abort();

   int * dest = malloc(sizeof(int)**size);

   for (unsigned int i = 0; i < *size; i++) dest[i] = src[i];

   return dest;
}

int *readArray(int * array, int * size) {
   if (!array) abort();

   int temp[10] = {0};
   *size = 0;
   while (scanf("%d", &temp[(*size)++]) && *size < 10);

   return copyArray(temp, size);
}
