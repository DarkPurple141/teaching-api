
typedef enum _day {
   MONDAY,
   ....
   SUNDAY
} day;

char *numToDay(day d) {

   char *day;
   ///assert(0 <= n && n <= 6);
   switch (d) {
      case SUNDAY: day = "Sunday";
      break;
      case MONDAY: day = "Monday";
      break;
      default:
         day = NULL;
   }

   return day;
}

if (condition) {
   int x = 10;
} else {
   int x = 20;
}

x = condition ? 10 : 20;

if (x == 0 || x < 10) {
   doSomethingCrazy()
} else {
   x = 20;
}

x = x == 0 || x < 10 ? doSomethingCrazy() : 20;

char *numToDay(int n){
    assert(0 <= n && n <= 6);
    char *day;
    if (n == 0) {
	     day = "Sun";
    }
    else if (n == 1) {
	     day = "Mon";
    }
    else if (n == 2) {
	     day = "Tue";
    }
    else if (n == 3) {
	     day = "Wed";
    }
    else if (n == 4) {
	     day = "Thu";
    }
    else if (n == 5) {
	     day = "Fri";
    }
    else if (n == 6) {
	     day = "Sat";
    }
    return  day;
}

// Pre:
// - a[] is a valid pointer to the start of an array of ints
// - n is a positive int indicating how many elements in a[]
// Post:
// - return value = ∀ i ∈ {0..n-2} ( a[i] ≤ a[i+1] )
bool isSorted(int *a, int n){
	...
}
