#include <stdio.h>
#include <stdlib.h>
#include "profile.c"

int fib(int x) {
  if (x == 0)
   return 0;
  else if (x == 1) 
    return 1;
  return fib(x - 1) + fib(x - 2);
}

int main(int argc, char *argv[]) {
 
  /* Timing the Fibonacci calculation for numbers from 1 to 45 */
  time_start("Fibcalc");
  unsigned int i;
  for (i = 1; i <= 100; ++i) {
    printf("Fibonacci for iter %d : %d\n", i, fib(39));
  }
  time_end("Fibcalc");
  time_summary();
  
  return 0;
}
