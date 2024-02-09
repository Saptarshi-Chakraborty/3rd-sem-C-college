#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int queue[MAX];
int FRONT = -1, REAR = -1;
void Enqueue();
void Dequeue();
void display();

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n\t\t--------- Circular Queue Operation ----------\n");
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
    }
}

void Enqueue()
{
    int data;
    if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1))
    {
        printf("\n\tQueue is full..! Can't Insert new element\n\n");
        return;
    }
    else
    {
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            if (REAR == MAX - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        printf("\nEnter the element : ");
        scanf("%d", &data);
        queue[REAR] = data;
    }
}

void Dequeue()
{
    if (FRONT == -1)
    {
        printf("\n\tQueue is empty..! Can't delete element\n\n");
        return;
    }
    else
    {
        printf("\n\tDeleted element is : %d\n", queue[FRONT]);
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            if (FRONT == MAX - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
}

void display()
{
    int i;
    if (FRONT == -1)
    {
        printf("\n\tCircular Queue is empty\n\n");
        return;
    }
    printf("\n \tFRONT (%d) ->\t| ", FRONT);
    if (FRONT <= REAR)
    {
        for (i = FRONT; i <= REAR; i++)
        {
            printf(" %d |", queue[i]);
        }
    }

    else
    {
        for (i = FRONT; i < MAX; i++)
        {
            printf(" %d |", queue[i]);
        }
        for (i = 0; i <= REAR; i++)
        {
            printf(" %d |", queue[i]);
        }
    }
    printf(" <- REAR (%d)\n", REAR);
}
