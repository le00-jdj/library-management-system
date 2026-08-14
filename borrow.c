#include "borrow.h"
#include <string.h>

void do_borrow(linklist head, const char *username)
{
    if (username == NULL || username[0] == '\0')
    { printf("请先登录\n"); return; }

    char isbn[20];
    printf("ISBN: "); scanf("%s", isbn);

    linklist p = find_by_isbn(head, isbn);   // 复用现成的查找
    if (p == NULL)      { printf("没有这本书\n"); return; }
    if (p->status == 1) { printf("已被 %s 借走\n", p->borrower); return; }

    p->status = 1;
    strcpy(p->borrower, username);
    printf("借阅成功\n");
}

void do_return(linklist head, const char *username)
{
    if (username == NULL || username[0] == '\0')
    { printf("请先登录\n"); return; }

    char isbn[20];
    printf("ISBN: "); scanf("%s", isbn);

    linklist p = find_by_isbn(head, isbn);
    if (p == NULL)      { printf("没有这本书\n"); return; }
    if (p->status == 0) { printf("这本书本来就在馆\n"); return; }
    if (strcmp(p->borrower, username) != 0) { printf("这不是你借的书\n"); return; }

    p->status = 0;
    p->borrower[0] = '\0';
    printf("还书成功\n");
}

void do_show_borrowers(linklist head)
{
    int count = 0;
    printf("======== 借阅情况(仅管理员) ========\n");
    for (linklist p = head->next; p != NULL; p = p->next)
    {
        if (p->status == 1)   /* 只打印借出的 */
        {
            printf("《%s》 ISBN:%s  -> 借阅者: %s\n",
                   p->book_name, p->ISBN, p->borrower);
            count++;
        }
    }
    if (count == 0)
        printf("当前没有借出的图书\n");
}
