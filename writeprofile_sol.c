#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "profile.c"
#define LEN 256
int main ()
{
   FILE * fp;
   char *sample_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla non lacus ex. Proin aliquam nibh eget elementum pulvinar. Morbi suscipit quam faucibus, mattis ligula eget, laoreet tortor.";
   struct stat st = {0};
   int i;

   if (stat("tmp", &st) == -1) {
      mkdir("tmp", 0700);
   }
   time_start("writeloop");
   for(i = 0; i < 100;i++){
       char fname[64];
       snprintf(fname, sizeof(char)*64, "tmp/tempfile.txt");
       fp = fopen(fname,"a");
       fprintf (fp, sample_text);
       fsync(fileno(fp));
       fclose(fp);
   }
   time_end("writeloop");
   time_summary();

   return 0;
}
