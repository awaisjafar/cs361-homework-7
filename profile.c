#include <time.h>
#include <string.h>
#include <sys/time.h>
#define NANOSECONDS_PER_SECOND 1E9

clock_t start, end;
double cpu_time_used;
char names[100][100];
struct timespec start_times[100];
struct timespec end_times[100];
int curval = 0;
void time_start(char *a){
/* Initialize the timing block with name given in the argument*/
	char tmp[100];
	strcpy(tmp,a);
	strcpy(names[curval],tmp);
	clock_gettime(CLOCK_REALTIME, &start_times[curval]);
	curval++;

}

void time_end(char *a){
  /* End of the timing block with the name given in the argument*/
  unsigned int i;
  unsigned int idx;
  for(i = 0; i < curval; ++i) {
      if (strcmp(names[i], a) == 0) {
          idx = i;
  	  break;
      }
  }
  clock_gettime(CLOCK_REALTIME, &end_times[idx]);
}

float elapsed_time(char *a){
    /* Time spend by the block with label a */
    unsigned int i,idx;
    for(i = 0; i < curval; ++i) {
        if (strcmp(names[i], a) == 0) {
            idx = i;
            break;
        }
    }
    double time_taken = (end_times[idx].tv_sec - start_times[idx].tv_sec) + (end_times[idx].tv_nsec - start_times[idx].tv_nsec)/NANOSECONDS_PER_SECOND;
    return time_taken;
}

float total_time(){
    /* Total time spent in all non-nesting blocks */
    double ctotal = 0;
    unsigned int i,idx;
    for(i = 0; i < curval; ++i) {
        ctotal += (end_times[i].tv_sec - start_times[i].tv_sec) + (end_times[i].tv_nsec - start_times[i].tv_nsec)/NANOSECONDS_PER_SECOND;
    }
    double time_taken = ctotal; // in seconds
    return time_taken;
}

int find_max(double a[], int n) {
  /* finding the maximum of a double array */
  int c, index;
  double max;

  max = a[0];
  index = 0;

  for (c = 1; c < n; c++) {
    if (a[c] > max) {
       index = c;
       max = a[c];
    }
  }

  return index;
}

float max_time(){
    /* finding the maximum of the time spent in all the blocks */
    double ctotal[100] = {0};
    unsigned int i,idx;
    for(i = 0; i < curval; ++i) {
        ctotal[i] = (end_times[i].tv_sec - start_times[i].tv_sec) + (end_times[i].tv_nsec - start_times[i].tv_nsec)/NANOSECONDS_PER_SECOND;
    }
    return ctotal[find_max(ctotal,100)];

}

void time_summary(){
  /* print the summary of the total times spent in all blocks */
    printf("\n");
    unsigned int i,idx;
    for(i = 0; i < curval; ++i) {
        double tdiff = (end_times[i].tv_sec - start_times[i].tv_sec) + (end_times[i].tv_nsec - start_times[i].tv_nsec)/NANOSECONDS_PER_SECOND; 
        double time_taken = tdiff; // in seconds
        printf("%s : %f seconds\n",names[i],time_taken);
    }

}

