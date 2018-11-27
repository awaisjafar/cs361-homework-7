#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "profile.c"
 
#define N_THREADS 100
 
/* Threads DataStructure for passing arguments  */
typedef struct _thread_data_t {
  int id;
} thread_data_t;

int fib(int x) {
  if (x == 0) 
    return 0;
  else if (x == 1) 
    return 1;
  return fib(x - 1) + fib(x - 2);
}

/* Thread function for getting Fibonacci value */
void *get_fib(void *arg) {

  /* Print the Fibonacci value for the given iteration */

}

int main(int argc, char **argv) {
  pthread_t thr[N_THREADS];
  int i, r_code,j;
  
  /* create an argument array */
  thread_data_t t_data[N_THREADS];

   /* Creating Threads */
  for (i = 0; i < N_THREADS; ++i) {
    /* Call the Fibonacci calculation function for the given value of i */
  }

  for (i = 0; i < N_THREADS; ++i) {
    /* Join the threads */
  }
 
  return EXIT_SUCCESS;
}
