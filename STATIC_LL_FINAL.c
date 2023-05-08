#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void lltrav(struct Node *ptr);
void llinsert_atbegin(struct Node *head);
void llinsert_atend(struct Node *head);
void llinsert_atindex(struct Node *head);
void lldelete_first(struct Node *head);            
void lldelete_last(struct Node *head);
void lldelete_atindex(struct Node *head);
void reverseList(struct Node * head) ;

int main()
{
    int choice;
    while (1)
    {

        struct Node *head;
        struct Node *second;
        struct Node *third;
        head = (struct Node *)malloc(sizeof(struct Node));
        second = (struct Node *)malloc(sizeof(struct Node));
        third = (struct Node *)malloc(sizeof(struct Node));
        head->data = 61;
        head->next = second;
        second->data = 48;
        second->next = third;
        third->data = 63;
        third->next = NULL;
        printf("\nBelow are Options to choose From : \n");
        printf("1.Displaying The Linked List (traversal)\n 2.Inserting at Beginning \n 3.Inserting at End \n 4.Inserting at any Index \n  5.Deletion of first Node \n 6.Deletion of Last Node \n 7.Deletion of Node of given Index\n 8.Reversing The Linked List\n9.EXIT");
        printf("\n");
        printf("Enter your Choice[1-8] : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            lltrav(head);
            break;
        case 2:
            llinsert_atbegin(head);
            break;
        case 3:
            llinsert_atend(head);
            break;
        case 4:
            llinsert_atindex(head);
            break;
        case 5:
            lldelete_first(head);
            break;
        case 6:
            lldelete_last(head);
            break;
        case 7:
            lldelete_atindex(head);
            break;
        case 8:
            reverseList(head) ;
            break; ;
        case 9 :
            exit(1) ;
            break; 
        default :
            printf("Enter Valid Choice \n") ;
        }
    }
    return 0;
}

void lltrav(struct Node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("The Data at index %d is : %d \t", i, ptr->data);
        printf("The address of next Node is %u \n", ptr->next);
        i++;
        ptr = ptr->next;
    }
}

void llinsert_atbegin(struct Node *head)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    int newdata;
    printf("Enter the data of new Node :");
    scanf("%d", &newdata);
    newnode->data = newdata;
    newnode->next = head;
    head = newnode;
    lltrav(head);
}

void llinsert_atend(struct Node *head)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    int newdata;
    printf("Enter Data in NewNode : ");
    scanf("%d", &newdata);
    newnode->data = newdata;

    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = NULL;
    lltrav(head);
}

void llinsert_atindex(struct Node *head)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    int newdata;
    printf("Enter Data for newnode :");
    scanf("%d", &newdata);
    int index, i = 1;
    printf("Enter The Index You Want to Enter Your Node :");
    scanf("%d", &index);
    newnode->data = newdata;
    struct Node *ptr = head;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    lltrav(head);
}

void lldelete_first(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    head = ptr->next;
    free(ptr);
    lltrav(head);
}

void lldelete_last(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL;
    free(ptr2);
    lltrav(head);
}

void lldelete_atindex(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    int index, i = 1;
    printf("The Index of Node which you want to Delete :");
    scanf("%d", &index);
    while (i != index - 1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        i++;
    }
    ptr1->next = ptr2->next;
    free(ptr2);
    lltrav(head);
}

void reverseList(struct Node * head) {
        struct Node  * prev = NULL, *cur=head, *next = NULL;
        while(cur!=NULL){
            next= cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
            lltrav(prev) ;
        return prev;
    
   }
   