#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "hashfun.h"

void hashfuncs(void *arg)
{
  fptr = fopen(arg, "r");
  char ch2 = fgetc(fptr);
  if (fptr == NULL)
  {
     printf("Unable to open file.Check this file exist or not!\n");
     exit(0);
  }
  if (ch2 == EOF)
  {
    printf("\n File is Empty '%s'\n", arg);
    exit(0);
  }

  int wordCursor = 0, sum = 0, key, wordCnt = 0;
  while (1)
  {
    char ch = fgetc(fptr);
    int c=ch;
    if (ch ==EOF)
       break;
    if (isalpha(ch) || isdigit(ch)) {
        if (wordCursor < 1000-1) {
	   newword[wordCursor++] = ch;
	   sum=sum+c;
	}
	continue;
    }
    else newword[wordCursor] = '\0';
    if (wordCursor == 0)
       continue;
    wordCursor=0;
    key=sum%TABLE_SIZE;
    sum = 0;

    if (hashtable[key].count == 0){
      if((strcmp("is", newword) == 0)||(strcmp("and", newword) == 0)||(strcmp("or", newword) == 0)||(strcmp("for", newword) == 0))
       {
         continue;
       }
       hashtable[key].count++;
       strcpy(hashtable[key].word, newword);
       wordCnt++;
    }
    else{
       struct node *head = &hashtable[key];
       int isFound = 0;
       while(1){
          if(strcmp(head->word, newword) == 0){
	     head->count++;
	     isFound = 1;
	     break;
          }
          if (head->next == NULL) break;
	     head = head->next;
       }
       if (isFound == 0){
	 head->next = (struct node *)malloc(sizeof(struct node));
         if (head->next == NULL){
	     printf("Unable to allocate memory.\n");
    	     exit(0);
         }
         head->next->next = NULL;
         head->count = 1;
         strcpy(head->word, newword);
         wordCnt++;
        }
     }
   }
}
