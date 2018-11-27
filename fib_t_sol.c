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

  thread_data_t *data = (thread_data_t *)arg;
  printf("Fib Value for %d : %d \n",data->id, fib(data->id));
  pthread_exit(NULL);

}

int main(int argc, char **argv) {
  pthread_t thr[N_THREADS];
  int i, r_code,j;
  /* create an argument array */
  thread_data_t t_data[N_THREADS];

 time_start("Fib_100");
  /* Creating Threads */
  for (i = 0; i < N_THREADS; ++i) {
    t_data[i].id = 39;
    if ((r_code = pthread_create(&thr[i], NULL, get_fib, &t_data[i]))) {
      fprintf(stderr, "Error in pthread_create: %d\n", r_code);
      return EXIT_FAILURE;
    }
  }

  for (i = 0; i < N_THREADS; ++i) {
    pthread_join(thr[i], NULL);
  }
  time_end("Fib_100");
  time_summary();

  return EXIT_SUCCESS;
}
