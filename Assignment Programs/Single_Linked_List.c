#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
} *head;
             
void createLinkedList();
void displayLinkedList();
void noOfNodes();
void linearSearch();

int main()
{
    int option;

    system("cls");
    printf("\n  --: SINGLEY LINEAR LINKED LIST :--\n\n");

    while (1)
    {
        printf("\n\t: AVAILABLE OPTIONS :\n\n");
        printf(" 1. Create Linked List\n 2. Display the Linked List\n 3. Number of Nodes\n");
        printf(" 4. Search for a Element\n 0. Exit\n");
        printf("\nEnter corresponding numbers of your choice : ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("\n\tTHANK YOU FOR USING THE PROGRAM\n");
            return 1;

        case 1:
            //	Creation

            createLinkedList();

            break;

        case 2:
            //	Deletion

            displayLinkedList();

            break;

        case 3:
            //	Search a Element

            noOfNodes();

            break;

        case 4:
            //	Sort array

            linearSearch();

            break;

        default:
            printf("\n\t!!! ERROR: Wrong Choice !!!\t");
        }

        printf("\nPress Enter to continue.... ");
        fflush(stdin);
        getchar();
        // system("cls");
    }

    printf("\n\nAfter calling all function, returned at main\n");

    return 0;
}

void createLinkedList()
{
    int length, i;
    struct NODE *newNode, *temp;

    printf("\nHow many nodes you want to create : ");
    scanf("%d", &length);

    head = (struct NODE *)malloc(sizeof(struct NODE));

    if (head == NULL)
    {
        printf("\n\t!!! ERROR : Unable to allocate memory !!!\n");
        return;
    }

    printf("\nEnter the data for node 1 : ");
    scanf("%d", &head->data);

    head->next = NULL;
    temp = head;

    for (i = 2; i <= length; i++)
    {
        newNode = (struct NODE *)malloc(sizeof(struct NODE));

        if (newNode == NULL)
        {
            printf("\n\t!!! ERROR : Unable to allocate memory !!!\n");
            return;
        }

        printf("\nEnter the data for node %d : ", i);
        scanf("%d", &newNode->data);

        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }

    printf("\n>> Linked List created successfully <<\n");
}

void displayLinkedList()
{
    struct NODE *temp;

    if (head == NULL)
    {
        printf("\n\t!!! ERROR : Linked List is empty !!!\n");
        return;
    }

    printf("\n\t>> Linked List <<\n\n HEAD -> ");

    temp = head;

    while (temp != NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }

    printf(" NULL\n");
}

void noOfNodes()
{
    struct NODE *temp;
    int count = 0;

    if (head == NULL)
    {
        printf("\n\t!!! ERROR : Linked List is empty !!!\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("\n\t>> Number of nodes in Linked List : %d <<\n", count);
}

void linearSearch()
{
    struct NODE *temp;
    int item, count = 1;
    
    if (head == NULL)
    {
        printf("\n\t!!! ERROR : Linked List is empty !!!\n");
        return;
    }

    printf("\nEnter the element to be searched : ");
    scanf("%d", &item);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("Item %d found at position %d\n", item, count);
            return;
        }
        count++;
        temp = temp->next;
    }

    printf("\n!!! Item %d not found in the Linked List !!!\n", item);
}

/*
    OUTPUT :

    --: SINGLEY LINEAR LINKED LIST :--

        : AVAILAVLE OPTIONS :

        1. Create Linked List
        2. Display the Linked List
        3. Number of Nodes
        4. Search for a Element
        0. Exit

    Enter corresponding numbers of your choice : 1

    How many nodes you want to create : 5

    Enter the data for node 1 : 12

    Enter the data for node 2 : 23

    Enter the data for node 3 : 34

    Enter the data for node 4 : 45

    Enter the data for node 5 : 56

    >> Linked List created successfully <<

    Press Enter to continue....

        : AVAILAVLE OPTIONS :

        1. Create Linked List
        2. Display the Linked List
        3. Number of Nodes
        4. Search for a Element
        0. Exit

    Enter corresponding numbers of your choice : 2

        >> Linked List <<

    HEAD ->  12 -> 23 -> 34 -> 45 -> 56 -> NULL

    Press Enter to continue....

        : AVAILAVLE OPTIONS :

        1. Create Linked List
        2. Display the Linked List
        3. Number of Nodes
        4. Search for a Element
        0. Exit

    Enter corresponding numbers of your choice : 3

    >> Number of nodes in Linked List : 5 <<

    Press Enter to continue....

        : AVAILAVLE OPTIONS :

        1. Create Linked List
        2. Display the Linked List
        3. Number of Nodes
        4. Search for a Element
        0. Exit

    Enter corresponding numbers of your choice : 4

    Enter the element to be searched : 34

    >> Item 34 found at position 3 <<

    Press Enter to continue....

        : AVAILAVLE OPTIONS :

        1. Create Linked List
        2. Display the Linked List
        3. Number of Nodes
        4. Search for a Element
        0. Exit

    Enter corresponding numbers of your choice : 4

    Enter the element to be searched : 100

    !!! Item 100 not found in the Linked List !!!

    Press Enter to continue....

        : AVAILAVLE OPTIONS :

        1. Create Linked List
        2. Display the Linked List
        3. Number of Nodes
        4. Search for a Element
        0. Exit

    Enter corresponding numbers of your choice : 0

        THANK YOU FOR USING THE PROGRAM

*/
