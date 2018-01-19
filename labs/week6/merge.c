
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "array.h"

static
void merge (int array[], int lo, int hi, int mid) {

   int i, j;
   i = j = 0;
   int n1 = mid - lo + 1;
   int n2 = hi - mid;
   int R[n1], L[n2];

   /* copy arrays */
   for (i = 0; i < n1; i++)
      L[i] = array[lo + i];
   for (j = 0; j < n2; j++)
      R[j] = array[mid + 1 + j];

   i = j = 0;
   while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            array[lo] = L[i++];
        else
            array[lo] = R[j++];
        lo++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        array[lo++] = L[i++];
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        array[lo++] = R[j++];
    }

}

void mergeSort(int * array, int lo, int hi) {
   if (lo < hi) {
      // find mid
      int mid = (lo + hi)/2;

      // mergeSort on lower half
      mergeSort(array, lo, mid);

      // mergeSort on upper half
      mergeSort(array, mid+1, hi);

      // now merge
      merge(array, lo, hi, mid);
   }
}
