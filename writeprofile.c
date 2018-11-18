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
   
   for(i = 0; i < 100;i++){
       /* Create a temporary file in the tmp folder 
          write the sample text in the file
          remember to use fsync and measure the time
          for all the iterations*/
   }

   return 0;
}
