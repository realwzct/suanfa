#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} person;

person *initLink(int n)
{
    int i = 0;
    person *head = NULL, *cyclic = NULL;
    head = (person *)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    cyclic = head;
    for (i = 2; i <= n; i++)
    {
        person *body = (person *)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;
        cyclic = cyclic->next;
    }
    cyclic->next = head; //首尾相连
    return head;
}

int main()
{
    person *head = NULL;
    head = initLink(4);
    return 0;
}