#include <stdio.h>
#include <stdlib.h>
typedef struct line
{
    struct line *prior;
    int data;
    struct line *next;
} line;
//双链表的创建
line *initLine(line *head);
//双链表插入元素，add表示插入位置
line *insertLine(line *head, int data, int add);
//双链表删除指定元素
line *delLine(line *head, int data);
//输出双链表的实现函数
void display(line *head);


int main()
{
    line *head = NULL;
    //创建双链表
    printf("初始链表为：\n");
    head = initLine(head);
    display(head);
    //在表中第 3 的位置插入元素 7
    printf("在表中第 3 的位置插入新元素 7：\n");
    head = insertLine(head, 7, 3);
    display(head);
    //表中删除元素 2
    printf("删除元素 2：\n");
    head = delLine(head, 2);
    display(head);
    return 0;
}
line *initLine(line *head)
{
    line *link;
    head = (line *)malloc(sizeof(line));
    head->next = NULL;
    head->prior = NULL;
    head->data = 1;
    link = head;
    for (int i = 2; i < 5; i++){
        line *body = (line *)malloc(sizeof(line));
        body->data = i;
        body->next = NULL;
        body->prior = NULL;
        link->next = body;
        body->prior = link;
        link = body;
    }
    return head;
}
line *insertLine(line *head, int data, int add)
{
    line *temp = (line *)malloc(sizeof(line));
    temp->data = data;
    temp->next = NULL;
    temp->prior = NULL;
    
    if(add == 1){
        temp->next = head;
        head->prior = temp;
        head = temp;
    }else{
        line *body = head;
        for (int i = 1; i < add-1; i++){
            body = body->next;
            if(body ==NULL){
                break;
            }
        }
        if (body)
        {
            if(body->next==NULL){
                body->next = temp;
                temp->prior = body;
            }else{
                body->next->prior = temp;
                temp->next = body->next;
                body->next = temp;
                temp->prior = body;
            }
        }
    }
    return head;
}
line *delLine(line *head, int data)
{
    line *temp = head;
    while (temp)
    {
        if(temp->data == data){
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    
    return head;
}
//head为原双链表，elem表示被查找元素

//输出链表的功能函数
void display(line *head)
{
    line *temp = head;
    while (temp)
    {
        if(temp->next==NULL){
            printf("%d\n", temp->data);
        }else
        {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }
    
}