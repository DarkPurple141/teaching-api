#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

static
void merge (int array[], int lo, int hi, int mid) {

   int i, j, k;
   j = mid;
   int n1 = mid - lo + 1;
   int n2 = hi - mid;
   int R[n1];
   int L[n2];


   while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            array[k] = L[i++];
        else
            array[k] = R[j++];
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        array[k++] = L[i++];
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        array[k++] = R[j++];
    }

}

void mergeSort(int * array, int lo, int hi) {
   if (hi > 1) {
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
