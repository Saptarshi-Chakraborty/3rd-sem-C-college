#include <stdio.h>
#include <stdlib.h>

void create();
void insertAtBeg(int item);
void insertAtPosition(int, int);
void insertAtEnd(int);
void deleteFromBeg();
void deleteFromEnd();
void deleteFromPosition(int);

void display();
int count();

struct Node
{
    int data;
    struct Node *next;
} *head;

int main()
{
    head = NULL;

    int choice, data, position;
    printf("-: SINGLE LINEAR LINKED LIST :-\n");

    while (1)
    {
        printf("0. EXIT\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(1);
        case 1:
            create();
            display();
            break;
        case 2:
            display();
            break;

        case 3:
            printf("Enter the data you want to insert : ");
            scanf("%d", &data);
            insertAtBeg(data);
            display();
            break;

        case 4:
            printf("Enter the data you want to insert : ");
            scanf("%d", &data);
            insertAtEnd(data);
            display();
            break;

        case 5:
            printf("Enter the data you want to insert : ");
            scanf("%d", &data);
            printf("\nEnter the position : ");
            scanf("%d", &position);

            insertAtPosition(data, position);
            display();
            break;

        case 6:
            deleteFromBeg();
            display();
            break;

        case 7:
            deleteFromEnd();
            display();
            break;

        case 8:
            printf("\nEnter the position : ");
            scanf("%d", &position);

            deleteFromPosition(position);
            display();
            break;

        default:
            printf("\n !!! Enter a valid option !!!\n");
        }
    }

    return 0;
}

void create()
{
    int noOfNodes, i, data, prevNoOfNodes = count();
    printf("How many nodes you want to create : ");
    scanf("%d", &noOfNodes);

    if (prevNoOfNodes > 0)
        printf("\nThere is already %d node(s) in the list. Appending new nodes\n", prevNoOfNodes);

    for (i = prevNoOfNodes; i < prevNoOfNodes + noOfNodes; i++)
    {
        printf("Enter data for node %d : ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }
}

void insertAtEnd(int item)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = item;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    for (temp = head; temp->next != NULL; temp = temp->next)
        ;
    temp->next = newNode;
}

void insertAtBeg(int item)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = item;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void insertAtPosition(int item, int position)
{
    struct Node *temp, *ptr;
    int count;

    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = item;
    temp->next = NULL;

    if (position == 1)
    {
        insertAtBeg(item);
        return;
    }

    ptr = head;
    for (count = 1; count < position - 1; count++)
    {
        ptr = ptr->next;
    }

    printf("\nAfter loop ptr->data = %d, count = %d\n", ptr->data, count);

    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteFromBeg()
{
    if (head == NULL)
    {
        printf("\n!!! The list is empty, Noting to delete !!! \n");
        return;
    }

    head = head->next;
}

void deleteFromEnd()
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("\n!!! The list is empty, Noting to delete !!! \n");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        return;
    }

    for (ptr = head; ptr->next->next != NULL; ptr = ptr->next)
        ;

    printf("\nAfter loop ptr->data = %d \n", ptr->data);

    ptr->next = NULL;
}

void deleteFromPosition(int position)
{
    struct Node *ptr, *prev;
    int count;
    if (head == NULL)
    {
        printf("\n!!! The list is empty, Noting to delete !!! \n");
        return;
    }
    else if (position == 1)
    {
        deleteFromBeg();
        return;
    }

    prev = head;
    ptr = head->next;
    count = 2;

    while (count < position)
    {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    prev->next = ptr->next;
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("\n !!! List is Empty !!!\n");
        return;
    }

    printf("\nHEAD ");
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf(" -> %d ", temp->data);
    }
    printf("\n\n");
}

int count()
{
    int c = 0;
    struct Node *temp;

    for (temp = head; temp != NULL; temp = temp->next)
    {
        c++;
    }

    return c;
}