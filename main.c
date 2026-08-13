#include"linklist.h"
#include"login.h"
#include"book.h"
#include"menu.h"

int main(void)
{
    ulinklist users = user_init();
    menu_main(users);     
    return 0;
}

 