#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>
#include "book.h"

linklist init_list(void);  
linklist insert_head(linklist head, book b);
linklist insert_tail(linklist head, book b);
linklist remove_tail(linklist head);
linklist remove_head(linklist head);
linklist find_by_isbn(linklist head, const char *isbn);
linklist remove_by_isbn(linklist head, const char *isbn);


void print(linklist head);


#endif