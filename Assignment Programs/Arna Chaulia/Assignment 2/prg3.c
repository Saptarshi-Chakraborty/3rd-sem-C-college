// prg 3 - Stack
#include <stdio.h>
#include <stdlib.h>

#define MAX 4
void display();
void push();
void pop();
void peek();

int Stack[MAX], top = -1;

int main()
{
    int option;
    while (1)
    {

        printf("\n\t\t--------- STACK OPERATIONS ----------\n");
        printf(" 0. Exit\n 1. PUSH\n 2. POP\n 3. PEEK\n 4. DISPLAY\n");
        printf("\nEnter a option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("\n\tTHANK YOU\n");
            exit(0);

        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;
        default:
            printf("\n\tERROR.. Wrong option !!!\t");
        }
        printf("\n\nPress Enter to continue.... ");
        getchar();
    }
    return 0;
}

void display()
{
    int r;
    if (top == -1)
    {
        printf("\n\tStack is empty..!\n\n");
        return;
    }
    printf("\nThe STACK is : \n");
    for (r = top; r >= 0; r--)
    {
        printf("\n\t| %d |", Stack[r]);
        if (r == top)
        {
            printf(" <---- [top]");
        }
    }
}

void push()
{
    int i, item;
    if (top == MAX - 1)
    {
        printf("\n\tStack is full...!\n\n");
        return;
    }
    printf("Enter new element : ");
    scanf("%d", &item);
    top = top + 1;

    Stack[top] = item;
    printf("\n Successfully pushed %d in the stack \n", item);
    display();
}

void pop()
{
    int k;
    if (top == -1)
    {
        printf("\n Stack is empty..!\n\n");
        return;
    }
    top = top - 1;
    printf("\n The element %d is successfully deleted from top \n", Stack[top + 1]);
    display();
}

void peek()
{
    if (top == -1)
    {
        printf("\n Stack is empty...!\n\n");
        return;
    }
    printf("\n\n Top of the stack = %d at index = %d  \n", Stack[top], top);
}

/*

        --------- STACK OPERATIONS ----------
 0. Exit
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY

Enter a option : 1

Enter new element : 1

 Successfully pushed 1 in the stack

The STACK is :

        | 1 | <---- [top]

Press Enter to continue....
        --------- STACK OPERATIONS ----------
 0. Exit
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY
    
Enter a option : 1

Enter new element : 2

 Successfully pushed 2 in the stack
    
The STACK is :

        | 2 | <---- [top]
        | 1 | 

Press Enter to continue....
        --------- STACK OPERATIONS ----------
 0. Exit
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY

Enter a option : 1

Enter new element : 3

 Successfully pushed 3 in the stack

The STACK is :

        | 3 | <---- [top]
        | 2 |
        | 1 | 

Press Enter to continue....
        --------- STACK OPERATIONS ----------
 0. Exit
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY

Enter a option : 1

Enter new element : 4

 Successfully pushed 4 in the stack

The STACK is :

        | 4 | <---- [top]
        | 3 |
        | 2 |
        | 1 |

Press Enter to continue....

        --------- STACK OPERATIONS ----------
 0. Exit
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY

Enter a option : 1

        Stack is full...!


Press Enter to continue....
        --------- STACK OPERATIONS ----------
 0. Exit
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY

Enter a option : 2
    
     The element 4 is successfully deleted from top

The STACK is :

        | 3 | <---- [top]
        | 2 |
        | 1 |

Press Enter to continue....
        --------- STACK OPERATIONS ----------
 0. Exit
 1. PUSH
 2. POP
 3. PEEK
 4. DISPLAY

Enter a option : 3

    Top of the stack = 3 at index = 2

Press Enter to continue....
        --------- STACK OPERATIONS ----------
    0. Exit
    1. PUSH
    2. POP
    3. PEEK
    4. DISPLAY

Enter a option : 4

The STACK is :

        | 3 | <---- [top]
        | 2 |
        | 1 |

Press Enter to continue....
        --------- STACK OPERATIONS ----------
    0. Exit
    1. PUSH
    2. POP
    3. PEEK
    4. DISPLAY

Enter a option : 2
    
         The element 3 is successfully deleted from top
    
The STACK is :
    
            | 2 | <---- [top]
            | 1 |

Press Enter to continue....
        --------- STACK OPERATIONS ----------
    0. Exit
    1. PUSH
    2. POP
    3. PEEK
    4. DISPLAY

Enter a option : 2
    
         The element 2 is successfully deleted from top

The STACK is :
    
            | 1 | <---- [top]   

Press Enter to continue....
        --------- STACK OPERATIONS ----------
    0. Exit
    1. PUSH
    2. POP
    3. PEEK
    4. DISPLAY

Enter a option : 2
    
         The element 1 is successfully deleted from top

The STACK is :
    
            Stack is empty..!

Press Enter to continue....
        --------- STACK OPERATIONS ----------
    0. Exit
    1. PUSH
    2. POP
    3. PEEK
    4. DISPLAY

Enter a option : 2
    
         Stack is empty..!

Press Enter to continue....
        --------- STACK OPERATIONS ----------
    0. Exit
    1. PUSH
    2. POP
    3. PEEK
    4. DISPLAY

Enter a option : 3

     Stack is empty...!

Press Enter to continue....
    
        --------- STACK OPERATIONS ----------
    0. Exit
    1. PUSH
    2. POP
    3. PEEK
    4. DISPLAY

Enter a option : 0
    
        THANK YOU 





*/