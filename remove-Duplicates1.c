#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDoplicates(struct ListNode *head);
void creatList(struct ListNode *first);
void printList(struct ListNode* head);

int main(void)
{
    struct ListNode L;
    struct ListNode *head=&L;
    head->val=-1;
    creatList(head);
    head=deleteDoplicates(head);
    printList(head);
    return 1;
}

struct ListNode* deleteDoplicates(struct ListNode *head)
{
    struct ListNode *p,*q=head;
    if(q==NULL)
    {
        return head;
    }
    p=q->next;
    while(p!=NULL)
    {
        if(p->val==q->val)
        {
            q->next=p->next;
            free(p);
            p=q->next;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    return head;
}
void creatList(struct ListNode *first)
{
    int endTag=-1,value;;
    struct ListNode *p;
    printf("input val:  ");
    scanf("%d",&value);
    if(value==endTag)
    {
        first->next=NULL;
    }
    else
    {
        first->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(first->next==NULL)
        {
            printf("Memory allocation error");
            exit(1);
        }
        first->next->val=value;
        creatList(first->next);
    }
}
void printList(struct ListNode* head)
{
    head=head->next;
    while(head!=NULL)
    {
        printf("%d\t",head->val);
        head=head->next;
    }
}
