#Homework 7 : Profiling in C


This homework will help you understand the following,

- How to profile a piece of code
- Quantify the performance boost using multithreading 
- I/O profiling

You skeleton code will comprise of the following


- <span style="color:red">Profiler.c </span> -  A helper functions library containing the code to measure the CPU execution time
- <span style="color:red">Fib.c</span>  - An Example code for profiling the Fibonacci numbers
- <span style="color:red">Fib_t.c</span> - This is the file you’ll modify in order to perform Fibonacci numbers calculation using multi-threading and report the performance gain for different values of number of threads.
- <span style="color:red">Fib_f.c</span> -  This is the file you need to modify in order to perform Fibonacci numbers calculation using forking of 3 children and equally dividing tasks among those. Report the time it takes for those to run.
- <span style="color:red">writeprofile.c</span> -  This file you’ll modify to check how much time it takes for the OS to open the same file over and over again and write content to it. You need to make sure that the data is written to the disk at each iteration. 

The profiles contains helper functions in order to calculate the CPU execution time for a given piece of code. Main modules of this library are as following

- <span style="color:blue">time_start( label )</span> -  Starting the measurement of execution time for the block starting with “label”
- <span style="color:blue">time_end( label )</span>  -  End of the block initialized with time_start() function having the tag “label”
- <span style="color:blue">total_time(  )</span>  -  The total amount of time for all the blocks combines. Return type of this is float
- <span style="color:blue">time_summary(  )</span> - Total time for each individual execution block labelled
- <span style="color:blue">elapsed_time( label )</span>  -  Total time of execution for the block having tag “label”

## Requirements

You’re required to perform the following tasks on two different machines and report the results (Min, Max and Average of 3 runs).

- Implement a multi-threading approach to get n fibonacci numbers. Compare the execution time against the single threaded approach used in Fib.c . Report the performance gain for num_threads = 2,5,10 and 45 threads. You can calculate upto Fib(45) for both of these approaches.
- Hope you guys remember forking that we used in one of the earlier homework. Use forking to create upto 3 children ( Hint : you only need to call fork() twice to do that ) and delegate the task in equal manner. I.e : parent calculates Fib(n) for n=1,5,9 and so on. Child 1 calculates Fib(n) for n=2,6,10 and so on. Child 2 calculates Fib(n) for n=3,7,11,.. And finally child 3 calculates Fib(n) for n=4,8,12,... . Calculate the time it took for solving the Fibonacci using this way and report the answers.
- Finally we try to profile IO performance. Modify  a tempfile in a loop and append the following text to it in each iteration, Be sure to make sure that the writes actually got written to the disk ( Hint : Use fsync )

“Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla non lacus ex. Proin aliquam nibh eget elementum pulvinar. Morbi suscipit quam faucibus, mattis ligula eget, laoreet tortor.”



