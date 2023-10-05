// prg 4 - Stack with Structure
#include <stdio.h>
#include <stdlib.h>

#define MAX 4

struct stack
{
    int top;
    int ar[MAX];
} stk;

void push();
void pop();
void peek();
void display();

int main()
{
    int option;

    system("cls");
    
    stk.top = -1;

    while (1)
    {
        system("cls");
        printf("\n\t\t--------- STACK OPERATIONS ----------\n");
        printf(" 0. Exit\n 1. PUSH\n 2. POP\n 3. PEEK\n 4. DISPLAY\n");
        printf("\nEnter your choice : ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 0:
            printf("\n\tTHANK YOU\n");
            exit(0);

        case 1:
            push();
            display();
            break;

        case 2:
            printf("\nPopped Elements.\n");
            pop();
            display();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        default:
            printf("\n\tERROR.. Wrong Choice !!!\t");
            break;
        }
        fflush(stdin);
        getchar();
    }

    return 0;
}

void push()
{
    if (stk.top == MAX - 1)
        printf("\nStack Overflow !");
    else
    {
        printf("\nEnter new element : ");
        scanf("%d", &stk.ar[++stk.top]);
    }
}

void pop()
{
    if (stk.top == -1)
    {
        return;
    }
    else
    {
        printf("\nThe %d Element is Popped.\n", stk.ar[stk.top--]);
    }
}

void peek()
{
    if (stk.top == -1)
        printf("\nStack Underflow!");
    else
    {
        printf("\nTop Elements is: %d\n", stk.ar[stk.top]);
    }
}

void display()
{
    int i;
    if (stk.top < 0)
        printf("\nStack Underflow!");
    else
    {
        printf("\n\nThe Stack is: \n");
        for (i = stk.top; i >= 0; i--)
        {
            printf("\n| %d |", stk.ar[i]);

            if (i == stk.top)
            {
                printf(" <--- [Top(%d)]", stk.top);
            }
        }
    }
}