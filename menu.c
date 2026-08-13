#include"linklist.h"
#include"login.h"
#include "borrow.h"
#include "menu.h"

book input_book(void)
{
    book b;
    printf("书名: ");  scanf("%s", b.book_name);
    printf("作者: ");  scanf("%s", b.author);
    printf("ISBN: ");  scanf("%s", b.ISBN);
    return b;
}


void do_add(linklist *phead, int role)
{
    if (role < 2) { printf("只有管理员才能录入图书！\n"); return; }   

    book b = input_book();
    if (find_by_isbn(*phead, b.ISBN) != NULL)  
    {
        printf("ISBN 已存在,录入失败\n");
        return;
    }
    *phead = insert_tail(*phead, b);
    printf("录入成功\n");
}

void do_show(linklist head)
{
    print(head);
}


void do_find(linklist head)
{
    char isbn[20];
    printf("ISBN: ");
    scanf("%s", isbn);
    linklist p = find_by_isbn(head, isbn);
    if (p) printf("找到:  书名:%s  作者: %s ISBN: %s\n", p->book_name, p->author, p->ISBN);
    else   printf("没有\n");
}


void do_del(linklist *phead, int role)
{
    if (role < 2) { printf("只有管理员才能删除图书！\n"); return; }   
    char isbn[20];
    printf("ISBN: ");
    scanf("%s", isbn);
    *phead = remove_by_isbn(*phead, isbn);
}

void book_menu(int role, linklist *phead, const char *username)

{
    int choice;
    while (1)
    {
        printf("\n===== 图书管理 =====\n");
         printf("1. 录入图书 \n2. 显示图书 \n3. 查找图书 \n4. 删除图书 \n5. 借书 \n6. 还书 \n7. 返回上一菜单\n8. 退出系统\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: do_add(phead, role);   break;   
        case 2: do_show(*phead);       break;   
        case 3: do_find(*phead);       break;
        case 4: do_del(phead, role);   break;
        case 5: do_borrow(*phead, username); break;
        case 6: do_return(*phead, username); break;
        case 7: return;
        case 0: exit(0);
        default: printf("无效选项\n");
        }
    }
}


/* ===== 注册界面 ===== */
void register_menu(ulinklist users)
{
    int choice;
    while (1)
    {
        printf("\n======== 注册界面 ========\n");
        printf("1. 管理员注册\n2. 读者注册\n3. 返回主菜单\n=========================\n");
        printf("请选择: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            char name[20], pwd[20];
            printf("管理员账号: "); scanf("%s", name);
            printf("密码: ");       scanf("%s", pwd);
            user_register(users, name, pwd, 2);
            printf("注册成功,请登录\n");
        }
        else if (choice == 2)
        {
            char name[20], pwd[20];
            printf("读者账号: "); scanf("%s", name);
            printf("密码: ");     scanf("%s", pwd);
            user_register(users, name, pwd, 1);
            printf("注册成功,请登录\n");
        }
        else if (choice == 3) return;
        else printf("无效选项\n");
    }
}


bool login_menu(ulinklist users, int *out_role, char *out_name)
{
    int choice;
    while (1)
    {
        printf("\n======== 登录 ========\n");
        printf("1. 管理员登录\n2. 读者登录\n3. 返回菜单\n===================\n");
        printf("请选择: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            char name[20], pwd[20];
            printf("账号: "); scanf("%s", name);
            printf("密码: "); scanf("%s", pwd);
            if (user_login(users, name, pwd, 2))
            {
                *out_role = 2;
                strcpy(out_name, name);      /* ★ 就多了这一行 */
                printf("管理员登录成功\n");
                return true;
            }
            printf("账号或密码错误\n");
        }
        else if (choice == 2)
        {
            char name[20], pwd[20];
            printf("账号: "); scanf("%s", name);
            printf("密码: "); scanf("%s", pwd);
            if (user_login(users, name, pwd, 1))
            {
                *out_role = 1;
                strcpy(out_name, name);      /* ★ 就多了这一行 */
                printf("读者登录成功\n");
                return true;
            }
            printf("账号或密码错误\n");
        }
        else if (choice == 3) return false;
        else printf("无效选项\n");
    }
}

/* ===== 总菜单(主界面) ===== */
void menu_main(ulinklist users)
{
    int role = 0, choice;
    char name[20] = "";                 /* ★ 新增:接用户名用的数组 */
    linklist head = init_list();

    while (1)
    {
        printf("\n======== 图书管理系统 ========\n");
        printf("1. 登录\n2. 注册\n3. 游客访问\n4. 退出\n=========================\n");
        printf("请选择: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (login_menu(users, &role, name))   /* ★ 传 name,函数会往里填 */
                book_menu(role, &head, name);     /* ★ 再往下传 */
        }
        else if (choice == 2)
            register_menu(users);
        else if (choice == 3)
            book_menu(0, &head, NULL);            /* ★ 游客:NULL=没名字 */
        else if (choice == 0) return;
        else printf("无效选项\n");
    }
}
