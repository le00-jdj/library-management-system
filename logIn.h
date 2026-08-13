#ifndef _USER_H_
#define _USER_H_
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct user
{
    char username[20];
    char password[20];
    int role;
    struct user *next;          /* 下一个用户 */
} user, *ulinklist;

ulinklist user_init(void);                                  /* 建空链表 */
ulinklist user_register(ulinklist head, const char *name, const char *pwd, int role);
bool      user_login(ulinklist head, const char *name, const char *pwd, int want_role);


#endif
