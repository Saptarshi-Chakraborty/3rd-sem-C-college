#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

void Enqueue();
void Dequeue();
void display();

int arr[MAX_SIZE], FRONT = -1, REAR = -1;

int main()
{
    int choice;
    while (1)
    {

        printf("\n\n\t\t--------- Linear Queue Operation ----------\n");
        printf(" 1. Enqueue\n 2. Dequeue\n 0. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("\n\tTHANK YOU FOR USING THE PROGRAM\n");
            exit(0);

        case 1:
            Enqueue();
            display();
            break;

        case 2:
            Dequeue();
            display();
            break;

        default:
            printf("\n\tERROR.. Wrong Choice !!!\t");
        }
        printf("\n\nPress Enter to continue.... ");
        getchar();
    }
    return 0;
}

void Enqueue()
{
    int data;
    if (REAR == MAX_SIZE - 1)
    {
        printf("\n\tQueue is full..! Can't Insert new element\n\n");
        return;
    }
    else
    {
        if (FRONT == -1)
        {
            FRONT = 0;
        }
        printf("\nEnter the data : ");
        scanf("%d", &data);
        REAR = REAR + 1;
        arr[REAR] = data;
    }
}

void Dequeue()
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("\n\tQueue is empty..! Can't delete an element\n\n");
        return;
    }
    else
    {
        printf("\n\tDeleted : %d\n", arr[FRONT]);
        FRONT = FRONT + 1;
    }
}

void display()
{
    int i;
    if (FRONT == -1)
    {
        printf("\n\tQueue is empty..!\n\n");
        return;
    }
    else
    {
        printf("\nThe Queue is : \n");
        for (i = FRONT; i <= REAR; i++)
        {
            if (i == FRONT)
            {
                printf(" FRONT (%d) --> |", FRONT);
            }

            printf(" %d |", arr[i]);

            if (i == REAR)
            {
                printf("  <-- REAR (%d)", REAR);
            }
        }
    }
}


/*
 OUTPUT : 
    
        --------- Linear Queue Operation ----------
    1. Enqueue
    2. Dequeue
    0. Exit

Enter your choice : 1

Enter the data : 10

The Queue is :
 FRONT (0) --> | 10 |  <-- REAR (0)

Press Enter to continue....

Enter your choice : 1

Enter the data : 20

The Queue is :
 FRONT (0) --> | 10 | 20 |  <-- REAR (1)

Press Enter to continue....


Enter your choice : 1

Enter the data : 30

The Queue is :
 FRONT (0) --> | 10 | 20 | 30 |  <-- REAR (2)

Press Enter to continue....

Enter your choice : 1

        Queue is full..! Can't Insert new element

the Queue is :
 FRONT (0) --> | 10 | 20 | 30 |  <-- REAR (2)

Press Enter to continue....

Enter your choice : 2

        Deleted : 10

The Queue is :
    FRONT (1) --> | 20 | 30 |  <-- REAR (2)

Press Enter to continue....
    

Enter your choice : 2

        Deleted : 20

The Queue is :
    FRONT (2) --> | 30 |  <-- REAR (2)

Press Enter to continue....

Enter your choice : 2

        Deleted : 30

The Queue is :
    FRONT (3) -->  <-- REAR (2)

Press Enter to continue....
    
Enter your choice : 2

        Queue is empty..! Can't delete an element

The Queue is :
    FRONT (3) -->  <-- REAR (2)

Press Enter to continue....
    
Enter your choice : 0

    THANK YOU FOR USING THE PROGRAM


*/

