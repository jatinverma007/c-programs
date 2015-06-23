#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node Node;

Node *head;
Node *tail;

void insert(int);
int fetch(int);
int display();
int main(int argc, char *argv[])
{
    int choice;
    int a;
    int value;
    int index;
    int remove_val();
    int remove_ind();
    while(1)
    {
        printf("What do you want to do?\n\n");
        printf("1. Insert \n2. Fetch \n3. Display \n4. Remove \n5.Exit \n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the value you want to insert!\n");
            scanf("%d", &value);
            insert(value);
            printf("\nInserted the value %d into linkedList\n", value);
            break;
        case 2:
            printf("\nValue at what index you want to fetch\n");
            scanf("%d", &index);
            value = fetch(index);
            printf("\nValue at index %d is %d\n", index, value); //need to fetch real value
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n How do you want to remove?? \n1.By Value \n2.By Index\n");
            scanf("%d",&a);
            switch(a)
            {
            case 1:
                remove_val();
                break;
            case 2:
                remove_ind();
                break;
            }
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }
}


void insert(int value)
{
    if(head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        head->value = value;
        head->next = NULL;
        tail = head;
    }
    else
    {
        tail->next = (Node *)malloc(sizeof(Node));
        tail->next->value = value;
        tail->next->next = NULL;
        tail = tail->next;
    }
}

int fetch(int index)
{
    int i;
    if(head == NULL)
    {
        return -1;
    }

    Node *pointer = head;
    for (i = 0; i < index; i++)
    {
        if(pointer->next == NULL)
        {
            return -1;
        }
        pointer = pointer->next;
    }

    return pointer->value;

}
int display()
{
    int i;
    Node *ptr;

    ptr=head;
    if (ptr==NULL)
    {
        printf("Linklist is empty\n");
    }

    else
    {
        printf("\nContent in the List.....\n");


        while(ptr->next!=NULL)
        {


            printf ("%d  ,  ",(ptr->value));
            ptr=ptr->next;


        }
        printf ("%d\n",(ptr->value));
        return 0;
    }
}
int remove_ind()
{
    int i,index;
    Node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("\nList does not exist\n");
        return 0;
    }
    printf("\n Which index to be removed??");
    scanf("%d",&index);
    if(index==0)
    {
        head=head->next;
        return 0;
    }
    for(i=0;i<index-1;i++);
    {
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;

    return 0;
}
int remove_val()
{
    int i,val;
    Node *ptr;
    Node *p;
    ptr=head;
    p=ptr;
    if(head==NULL)
    {
        printf("\n List does not exist\n;");
        return 0;
    }
    printf("\nWhich value to be removed???");
    scanf("%d",&val);
    if(head->value==val)
    {
        head=head->next;
        return 0;
    }
    while(ptr!=NULL)
    {
        if(ptr->value==val)
        {
            p->next=p->next->next;
            return 0;
        }
        else
        {
            p=ptr;
            ptr=ptr->next;
        }
    }
    return 0;
}

