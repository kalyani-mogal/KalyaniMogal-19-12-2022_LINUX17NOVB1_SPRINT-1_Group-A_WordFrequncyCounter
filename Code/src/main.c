#include<stdio.h>
#include<pthread.h>
//#include<stdlib.h>
#include<unistd.h>
#include "hashfun.h"

int main(int argc, char *argv[])
{
  pthread_t threads[argc-1];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  int i;

  for (i = 0; i < TABLE_SIZE; i++) {
     hashtable[i].word[0] = '\0';
     hashtable[i].count = 0;
     hashtable[i].next = NULL;
  }
  for (i=1; i<argc; i++){
     char* arguments;
     arguments = argv[i];
     pthread_create(&threads[i], &attr,(void*) hashfuncs, (void*)arguments);
   }
  for (i=1; i<argc; i++){
     pthread_join(threads[i], NULL);
   }
  printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
  printf("                                  WELCOME");
  printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
  printf("\nProcessing......\n");
  printf("\a");
  sleep(3);
  printf("-------------------- Words and their frequency count ------------------- \n\n");

  for(i = 0; i < TABLE_SIZE; i++)
  {
    if (hashtable[i].count != 0)
    printf("   %s :  %d\n",hashtable[i].word,hashtable[i].count);
  }
  printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
}
