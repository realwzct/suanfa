#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Link
{
    int elem;          //代表数据域
    struct Link *next; //代表指针域，指向直接后继元素
} link;

int num[5] = {0};

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

void reservelink(link *head){
    if (head == NULL)
        return;
    reservelink(head->next);
    printf("%d ", head->elem);
}

link *recursive_reverse(link *head)
{
    //递归的出口
    if (head == NULL || head->next == NULL) // 空链或只有一个结点，直接返回头指针
    {
        return head;
    }
    else
    {
        //一直递归，找到链表中最后一个节点
        link *new_head = recursive_reverse(head->next);
        //当逐层退出时，new_head 的指向都不变，一直指向原链表中最后一个节点；
        //递归每退出一层，函数中 head 指针的指向都会发生改变，都指向上一个节点。
        //每退出一层，都需要改变 head->next 节点指针域的指向，同时令 head 所指节点的指针域为 NULL。
        head->next->next = head;
        head->next = NULL;//不防空的最后不好判断
        //每一层递归结束，都要将新的头指针返回给上一层。由此，即可保证整个递归过程中，能够一直找得到新链表的表头。
        return new_head;
    }
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

    link *m = recursive_reverse(b->next);

    display(m);
    return 0;
}