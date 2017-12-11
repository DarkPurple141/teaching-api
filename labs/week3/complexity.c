
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
   all even
*/
bool allEven (int a[], int l, int r) {
      // TODO
}
