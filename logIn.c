#include "login.h"

ulinklist user_init(void)
{
    ulinklist head = (ulinklist)malloc(sizeof(user));
    if (head == NULL)
    {
        printf("创建失败\n");
        exit(1);
    }
    head->next = NULL;
    return head;
}

ulinklist user_register(ulinklist head, const char *name, const char *pwd, int role)
{
    /* 查重 */
    for (ulinklist p = head->next; p != NULL; p = p->next)
        if (strcmp(p->username, name) == 0)
        {
            printf("用户名已存在\n");
            return head;
        }
    /* 新节点 */
    ulinklist new = (ulinklist)malloc(sizeof(user));
    if (new == NULL)
    {
        printf("创建失败\n");
        return head;
    }
    strncpy(new->username, name, 19);   new->username[19] = '\0';
    strncpy(new->password, pwd, 19);    new->password[19] = '\0';
    new->role = role;                   /* ← 新增:把身份写进节点 */
    new->next = NULL;
    /* 尾插 */
    ulinklist p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = new;
    return head;
}

bool user_login(ulinklist head, const char *name, const char *pwd, int want_role)
{
    for (ulinklist p = head->next; p != NULL; p = p->next)
        if (p->role == want_role                    /* ← 新增:身份必须匹配 */
            && strcmp(p->username, name) == 0
            && strcmp(p->password, pwd) == 0)
            return true;
    return false;
}
