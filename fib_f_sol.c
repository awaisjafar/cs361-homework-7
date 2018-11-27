
#include <unistd.h> 
#include <stdio.h> 
#include "profile.c"


int fib(int x) {
  if (x == 0) return 0;
  else if (x == 1) return 1;
  return fib(x - 1) + fib(x - 2);
}

void  Child1Process(void)
{
     int   i;

     for (i = 1; i <= 25; i=i+1)
          printf("Child 1 Fib call for iter = %d, value = %d\n", i,fib(39));
}

void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= 25; i=i+1)
          printf("Parent Fib call for iter = %d, value = %d\n", i,fib(39));
}

void  Child2Process(void)
{
     int   i;

     for (i = 1; i <= 25; i=i+1)
          printf("Child 2 Fib call for iter = %d, value = %d\n", i,fib(39));
}

void  Child3Process(void)
{
     int   i;

     for (i = 1; i <= 25; i=i+1)
          printf("Child 3 Fib call for iter = %d, value = %d\n", i,fib(39));
}



int main()
{
    int f1 = fork();
    int f2 = fork();

    if (f1 > 0 && f2 > 0) {
        time_start("parent");
    	ParentProcess();
    	time_end("parent");
    }
    else if (f1 == 0 && f2 > 0)
    {
    	time_start("child1");
    	Child1Process();
        time_end("child1");
    }
    else if (f1 > 0 && f2 == 0)
    {
    	time_start("child2");
    	Child2Process();
        time_end("child2");
    }
    else {
    	time_start("child3");
    	Child3Process();
        time_end("child3");
    }
    time_summary();
    return 0;
}


