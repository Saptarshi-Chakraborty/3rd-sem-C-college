#include <stdio.h>
#include <stdlib.h>

void create();
void insertAtEnd(item);

struct Node
{
    int data;
    struct Node *next;
} *head;

int main()
{
    head = NULL;

    int choice, data, position;
    printf("-: SINGLE CIRCULAR  LINKED LIST :-\n");

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
            break;

        default:
            printf("\n !!! Enter a valid option !!!\n");
        }
    }

    return 0;
}

// END