/* 
 * WHAT THIS EXAMPLE DOES
 * 
 * We create a pool of 4 threads and then add 40 tasks to the pool(20 task1 
 * functions and 20 task2 functions). task1 and task2 simply print which thread is running them.
 * 
 * As soon as we add the tasks to the pool, the threads will run them. It can happen that 
 * you see a single thread running all the tasks (highly unlikely). It is up the OS to
 * decide which thread will run what. So it is not an error of the thread pool but rather
 * a decision of the OS.
 * 
 * */

#include <stdio.h>
#include <pthread.h>
#include "thpool.h"
#include "profile.c"

int fib(int x) {
  if (x == 0) 
    return 0;
  else if (x == 1) 
    return 1;
  return fib(x - 1) + fib(x - 2);
}


void fibcalc(){
	printf("Thread #%u calculating Fib value of 39 : %d \n", (int)pthread_self(),fib(39));
}


int main(){
	
	puts("Making threadpool with 5 threads");
	threadpool thpool = thpool_init(2);

	puts("Adding 100 tasks to threadpool");
	time_start("Fib_pool");
	int i;
	for (i=0; i<100; i++){
		thpool_add_work(thpool, (void*)fibcalc, NULL);
	};

	puts("Waiting for work queue to be empty");
	thpool_wait(thpool);
	time_end("Fib_pool");
	time_summary();
	
	return 0;
}
