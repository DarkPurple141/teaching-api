#include <stdlib.h>
#include "sort.h"
#include "array.h"

int main(void) {
   int size; int * array;

   array = readArray(array, &size);
   mergeSort(array, 0, size - 1);
   printArray(array, size);
   free(array);
}
