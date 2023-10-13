#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
} *start;

void createLL();
void displayLL();
int countNodes();
void searchNode();

int main()
{
    int choice;
    start = NULL;
    system("CLS");
    while (1)
    {
        printf("\n\t\t-----|LINKED LIST OPERATIONS|-----\n");
        printf("\n0.Exit\n1.Create\n2.Display\n3.Count Nodes\n4.Search Nodes\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("\nExiting the program.\n");
            exit(0);

        case 1:
            printf("\n\t\tCREATING LINKED LIST");
            createLL();
            displayLL();
            break;

        case 2:
            printf("\n\t\tLINKED LIST");
            displayLL();
            break;

        case 3:
            printf("\nNumber of nodes:%d\n", countNodes());
            break;

        case 4:
            displayLL();
            searchNode();

        default:
            printf("SORRY!!! Invalid Choice!!!");
        }
    }
    return 0;
}

void createLL()
{
    int data, n, i;
    struct Node *ptr;
    struct Node *ptr2;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter data for first node: ");
    scanf("%d", &data);
    ptr->info = data;
    ptr->link = NULL;
    start = ptr;
    for (i = 2; i <= n; i++)
    {
        ptr2 = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter data for node %d: ", i);
        scanf("%d", &ptr2->info);
        ptr2->link = NULL;
        ptr->link = ptr2;
        ptr = ptr2;
    }
}

void displayLL()
{
    struct Node *temp;
    if (start == NULL)
    {
        printf("\n!!!LINKED LIST IS EMPTY!!!\n");
        return;
    }
    temp = start;
    printf("\nLINKED LIST:\nHEAD -> |");
    while (temp->link != NULL)
    {
        printf(" %d |", temp->info);
        temp = temp->link;
    }
    printf(" %d | -> NULL\n", temp->info);
}

int countNodes()
{
    int c;
    struct Node *temp;
    if (start == NULL)
        return 0;
    for (temp = start, c = 0; temp->link != NULL; temp = temp->link, c++)
        ;
    return (c + 1);
}

void searchNode()
{
    struct Node *temp;
    int s, flag = 0, c;
    if (start == NULL)
    {
        printf("\n!!!LINKED LIST IS EMPTY!!!\n");
        return;
    }
    printf("\nEnter the element you want to search : ");
    scanf("%d", &s);
    printf("\nSearching for %d.\n", s);
    for (temp = start, c = 1; temp->link != NULL; temp = temp->link, c++)
    {
        if (temp->info == s)
        {
            printf("| Item %d found in Node %d |\n", s, c);
            flag = 1;
        }
    }
    if (temp->info == s)
    {
        printf("| Item %d found in Node %d |\n", s, c);
    }
    else if (flag == 0)
    {
        printf("!!! Item %d not found in the List !!!\n", s);
    }
}