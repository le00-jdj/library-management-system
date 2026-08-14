#ifndef _BORROW_H
#define _BORROW_H
#include "linklist.h"

void do_borrow(linklist head, const char *username);
void do_return(linklist head, const char *username);
void do_show_borrowers(linklist head);

#endif
