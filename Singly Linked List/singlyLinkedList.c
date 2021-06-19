#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

typedef struct list list;

// prototype
void display(list*);
void countNode(list*);
void addEnd(list*, int);
void addBegin(list **, int);
void addAnyPos(list*, int, int);
void delFirst(list**);
void delLast(list*);
void delAnyPos(list**, int);
list* reverse(list*);
list* del_Linked_List(list*);

int main()
{
    list* head = NULL;
    head =(list*)malloc(sizeof(list));
    head->data=40;
    head->next=NULL;

    // adding data in list
    addEnd(head,15);
    addBegin(&head,35);
    addAnyPos(head,17,2);

    // display list
    display(head);

    // reverse list
    head = reverse(head);
    // display reverse
    display(head);

    // delet data in list
    delFirst(&head);
    delLast(head);


    return 0;
}


// define function-> as below
// display node
void display(list *head)
{
    if (head==NULL)
        printf("linked list is empty");

    list *ptr = NULL;
    ptr = head;

    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } 
    printf("\n");
}

// count of node
void countNode(list *head)  
{
    int count = 0;
    if (head==NULL)
        printf("linked list is empty");

    list *ptr = NULL;
    ptr = head;

    while (ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    } 
    printf("%d",count);
}

// add at the end
void addEnd(list *head, int data)
{
    list *ptr, *temp;
    ptr = head;
    temp = (list*)malloc(sizeof(list));

    temp->data=data;
    temp->next=NULL;

    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    
}

// add at the begining
void addBegin(list **head, int data)
{
    list* temp = (list*)malloc(sizeof(list));
    temp->data=data;
    temp->next=NULL;
    temp->next=*head;
    *head=temp;
}

// add at any position
void addAnyPos(list* head, int data, int pos)
{
    list *ptr, *var;
    ptr = head;
    var = malloc(sizeof(struct list));
    var->data = data;
    var->next = NULL;

    pos--;
    while (pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }

    var->next=ptr->next;
    ptr->next=var;
    
}

// delet first
void delFirst(list** head)
{
    if(*head==NULL)
        printf("list is empty: ");
    list *temp = *head;
    *head = temp->next;
    free(temp);
    temp=NULL;
}


// delet last node
void delLast(list* head)
{
    if(head==NULL)
        printf("list is empty: ");

    else if (head->next==NULL) {
        free(head);
        head = NULL;
    }  

    else {
        
        list *temp = head;
        while (temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}


// delet any position
void delAnyPos(list** head, int pos) {
    list *current, *previous;
    current = previous = *head;

    if(*head==NULL)
        printf("linked list is empty");

    else if(pos==1) {
        *head = current->next;
        free(current);
        current = NULL;
    }

    else {
        while (pos!=1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    } 
}

// delet entire list
list* del_Linked_List(list* head)
{
    struct list *temp = head;

    while (temp!=NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
    return head;
}

// reverse list
list* reverse(list* head)
{
    list *prev, *curr;
    prev = curr = NULL;

    while (head != NULL)
    {
        curr = head->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    head = prev;
    return head;
}


