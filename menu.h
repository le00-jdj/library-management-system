#ifndef _MENU_H
#define _MENU_H
#include"login.h"
#include"linklist.h"
   
void menu_main(ulinklist users);
void register_menu(ulinklist users);
void menu_main(ulinklist users);
void book_menu(int role, linklist *phead, const char *username);
bool login_menu(ulinklist users, int *out_role, char *out_name);


#endif