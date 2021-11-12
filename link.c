#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Link
{
    int elem;                                  //代表数据域
    struct Link *next;                          //代表指针域，指向直接后继元素
} link;

link *initLink()
{
    link *p = (link *)malloc(sizeof(link)); //创建一个头结点
    link *temp = p;                         //声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (int i = 1; i < 5; i++)
    {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

link *insertElem(link *p, int elem, int add)
{
    link *temp = p; //创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++)
    {
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    //创建插入结点c
    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return p;
}

link *delElem(link *p, int add)
{
    link *temp = p;
    //遍历到被删除结点的上一个结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    link *del = temp->next;        //单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; //删除某个结点的方法就是更改前一个结点的指针域
    free(del);                     //手动释放该结点，防止内存泄漏
    return p;
}

void display(link *p)
{
    link *temp = p; //将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}

int main(void)
{
    link *b = initLink();
    // display(b);
    b = insertElem(b, 55, 3);
    // display(b);
    // b = delElem(b, 1);
    // display(b);
    return 0;
}