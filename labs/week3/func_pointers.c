
#include <stdio.h>

int isValue(int n, int (*func)(int number)) {
   return func(n);
}

int isOdd(int n) {
   return (n % 2 != 0);
}

int isEven(int n) {
   return (n % 2 == 0);
}

int main(int argc, char const *argv[]) {

   // these are being passed to isValue which then checks using the function
   // passed to them

   printf("Expected is 0 == %d\n", isValue(12, isOdd));
   printf("Expected is 1 == %d\n", isValue(12, isEven));

   return 0;
}
