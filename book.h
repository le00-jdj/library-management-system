#ifndef _BOOK_H_
#define _BOOK_H_

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node
{
    char book_name[20];
    char author[20];
    char  ISBN[20];
     int   status;            
    char  borrower[20];      
    struct node*next;
}book,*linklist;

 
#endif

