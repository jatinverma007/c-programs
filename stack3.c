#include<stdio.h>
#define size 3
typedef struct stack stk;
struct stack
{
    int top;
    int store[size];
};
void push(stk *);
void pop(stk *);
void disp(stk *);

void main()
{
    stk s;
    int ch;
    s.top=-1;
    do
    {
        printf("\n\n----- STACK MENU -----\n");
        printf("1. Push an Element in Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("PLEASE ENTER VALID CHOICE....\n");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
        case 1:
        {
            push(&s);
            break;
        }
        case 2:
        {
            pop(&s);
            break;
        }
        case 3:
        {
            disp(&s);
            break;
        }
        case 4:
        {
            break;
        }
        }
    }
    while(ch!=4);

}
void menu()
{

}
void push(stk *s)
{
    int i;
    if(s->top==size-1)
    {
        printf("Stack is Overflowed\n");
    }
    else
    {
        printf("Enter the Element\n");
        scanf("%d",&i);
        s->top++;
        s->store[s->top]=i;
    }
}
void pop(struct stack *s)
{
    int i;
    if(s->top==-1)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        i=s->store[s->top];
        s->top--;
        printf("Removed Value %d",i);
    }
}
void disp(stk *s)
{
    int i=s->top;
    if(i==-1)
        printf("Empty Stack");
    while(i!=-1)
    {
        printf("%d\n",s->store[i]);
        i--;

    }
}
