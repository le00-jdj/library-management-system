#include "linklist.h"

linklist init_list(void)
{
    linklist head = (linklist)malloc(sizeof(book));
    if (head == NULL)
    {
        printf("创建失败\n");
        return NULL;
    }
    head->next = NULL;
    return head;
}

linklist insert_head(linklist head, book b)
{
    linklist new = (linklist)malloc(sizeof(book));
    if (new == NULL)
    {
        printf("创建失败\n");
        return NULL;
    }
    *new = b;              
    new->next = head->next;
    head->next = new;
    printf("加入图书成功！\n");
    return head;
}

linklist insert_tail(linklist head, book b)
{
    linklist new = (linklist)malloc(sizeof(book));
    if (new == NULL)
    {
        printf("创建失败\n");
        return NULL;
    }
    *new = b;
    new->next = NULL;

    if (head->next == NULL)
    {
        head->next = new;
        return head;
    }
    linklist p = head->next;
    while (p->next != NULL)
        p = p->next;
    p->next = new;
    printf("加入图书成功！\n");
    return head;
}

linklist remove_tail(linklist head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL)
    {
        printf("表已经空了\n");
        return head;
    }
    linklist p = head->next;
    while (p->next->next != NULL)
        p = p->next;
    linklist q = p->next;
    p->next = NULL;
    free(q);
    printf("删除图书成功！\n");
    return head;
}

linklist remove_head(linklist head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL)
    {
        printf("表已经空了\n");
        return head;
    }
    linklist p = head->next;
    head->next = p->next;
    free(p);
    printf("删除图书成功！\n");
    return head;
}

linklist find_by_isbn(linklist head, const char *isbn)
{
    linklist p = head->next;               
    while (p != NULL)                     
    {
        if (strcmp(p->ISBN, isbn) == 0)   
            return p;                   
        p = p->next;                       
    }
    return NULL;                          
}

linklist remove_by_isbn(linklist head, const char *isbn)
{
    linklist p = head;                     
    while (p->next != NULL)                
    {
        if (strcmp(p->next->ISBN, isbn) == 0)   
        {
            linklist q = p->next;           
            p->next = q->next;              
            free(q);                       
            printf("已删除 ISBN 为 %s 的书\n", isbn);
            return head;                   
        }
        p = p->next;                        
    }
    printf("没有找到 ISBN 为 %s 的书\n", isbn);
    return head;                          
}



void print(linklist head)
{
    if (head->next == NULL)
    {
        printf("书库为空\n");
        return;
    }
    for (linklist p = head->next; p != NULL; p = p->next)
        printf("%s  %s  %s\n", p->book_name, p->author, p->ISBN);
    printf("\n");
}
