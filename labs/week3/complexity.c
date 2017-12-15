
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
   What is my time complexity?
*/
void nestedLoops(int n) {
   int i, j;
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
         printf("hello");
      }
   }
}

/*
   Search an array for a value
*/
bool found(int a[], int n, int val) {
     int i;
     for (i = 0; i < n; i++) {
         if (a[i] == val) return 1;
    }
    return 0;
}

/*
   all even { 0, 2, 2, 3, 5 }
*/
bool allEven (int a[], int l, int r) {
   // base case for exit
   if (r < 1) return 1;
   // second base case l == r
   if (l == r) return a[l] % 2 == 0;

   int mid = (l + r) / 2;

   int result = allEven(a, l, mid);

   if (result == 1) {
      result = allEven(a, mid+1, r);
   }

   return result;

}
