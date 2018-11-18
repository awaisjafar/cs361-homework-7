
#include <unistd.h> 
#include <stdio.h> 
#include "profile.c"


int fib(int x) {
  if (x == 0) 
    return 0;
  else if (x == 1) 
    return 1;
  return fib(x - 1) + fib(x - 2);
}

void  Child1Process(void)
{
     int   i;
     // Run the loop as given in the instructions
}

void  ParentProcess(void)
{
     int   i;
     // Run the loop as given in the instructions
     
}

void  Child2Process(void)
{
     int   i;
     // Run the loop as given in the instructions
     
}

void  Child3Process(void)
{
     int   i;
     // Run the loop as given in the instructions
}



int main()
{
   
   /* Create 3 child processes and Find time spent in each. 
   You'd have to report the maximum of the time spent of all
   since we're forking each each process would have a different
   profiler attached to it */ 

    return 0;
}


