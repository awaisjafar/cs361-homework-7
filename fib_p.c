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

	 // Fibonacci number calculation

}


int main(){
	
	puts("Initialize threadpool with 5 threads");

	threadpool thpool = thpool_init(5);

	puts("Adding 100 tasks to threadpool");

	int i;
	for (i=1; i<=100; i++){

		// Call the fibcalc function to find the Fibonacci number of 39
	
	};

	puts("Waiting for work queue to be empty");

	// Wait for threads to finish work
	
	return 0;
}
