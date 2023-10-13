// Now : Single Linear Linked List
/* HW : 3a. Liner Queue using Structure Pointer
   HW : 3b. Circular Queue using Structure Pointer
   Menu : Enqueue, Dequeue, Exit (display func deault after each menu)
   Assignment Title : Implementation of Queue Operations
			  Objective: 1. Linear Queue
						 2. Circular Queue
*/

#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
} *head;

void createLinkedList();
void display();
void insertNodeAtEnd(int);
int countNumberOfNodes();
void insert();
void insertAtPosition(int, int);
void search();

int main()
{
	int choice;

	head = NULL; // Initialize the head

	while (1)
	{

		printf("\n\t---- SINGLE LINEAR LINKED LIST ----\n\n");

		printf(" 0. Exit\n 1. Create\n 2. Displaty\n 3. Count\n 4. Insertion\n");
		printf(" 5. Deletion\n 6. Search\n 7. Sort\n 8. Reverse\n");
		printf("\nEnter the corresponding number of your choice : ");
		scanf("%d", &choice);

		//printf("\n\tYOUR CHOICE = %d\n\n", choice); // DEBUG

		switch (choice)
		{
		case 0:
			//	Exit
			printf("\n THANK YOU FOR USING THIS PROGRAM \n");
			return 1;

		case 1:
			//	Create List - LAB WORK
			printf("\n\t-: LINKED LIST CREATION :-\n\n");
			createLinkedList();
			display();
			break;

		case 2:
			//	Display List - LAB WORK
			display();
			break;

		case 3:
			//	Count number of nodes - LAB WORK
			printf("\n\t>> NUMBER OF NODES IN THE LIST IS : %d <<\n\n", countNumberOfNodes());
			break;

		case 4:
			//	Insertion
			display();

			printf("\t: NODE INSERTION :");
			insert();
			display();
			break;

		case 5:
			//	Deletion
			break;

		case 6:
			//	Search - LAB WORK
			display();

			search();
			break;

		case 7:
			//	Sort the List
			break;

		case 8:
			//	Revese List
			break;

		default:
			printf("\n\t!!! WRONG CHOICE !!!\nEnter the number of your choice correctly\n");
		}

		printf("\nPress Enter to Continue...");
		fflush(stdin);
		getchar();
		system("cls");

		//		return 1;
	}

	return 0;
}

void createLinkedList()
{
	//	printf(" \n\t createLinkedList : FUNCTION START \n"); // DEBUG

	int size, i, data;

	printf("How many nodes you want to create : ");
	scanf("%d", &size);

	for (i = 0; i < size; i++)
	{
		printf("\nEnter value for node %d : ", i + 1);
		scanf("%d", &data);

		insertNodeAtEnd(data);
	}

	printf("\n>> The Linked List initialized successfully with %d nodes <<\n\n", size);

	//	Display the whole list in current function -> DEBUG
	//	p = head;
	//	printf("LIST IS : \n");
	//	while(p->next != NULL){
	//		printf("%d\n", p->data);
	//		p = p->next;
	//	}
	//		printf("%d\n", p->data);
	//	printf("\nLIST END\n");

	// printf(" \n\t createLinkedList : FUNCTION EXIT \n"); // DEBUG
}

void insertNodeAtEnd(int data)
{
	struct NODE *temp, *p;

	temp = (struct NODE *)malloc(sizeof(struct NODE));

	temp->data = data;
	temp->next = NULL;

	if (head == NULL)
		head = temp;
	else
	{
		for (p = head; p->next != NULL; p = p->next)
			;
		p->next = temp;
	}
}

void display()
{
	//	printf("\n\t display : FUNCTION START\n\n"); // DEBUG
	struct NODE *temp;

	if (head == NULL)
	{
		printf("\n !!! LINKED LIST IS EMPTY. CAN'T DISPLAY ANYTHING !!!\n\n");
		return;
	}

	temp = head;

	printf("\nLINKED LIST:\n\n HEAD -> |");
	while (temp->next != NULL)
	{
		printf(" %d |", temp->data);

		temp = temp->next;
	}
	printf(" %d | -> NULL\n\n", temp->data);

	//	printf("\n\t display : FUNCTION EXIT\n\n"); // DEBUG
}

int countNumberOfNodes()
{
	int count;
	struct NODE *temp;

	if (head == NULL)
		return 0;

	for (temp = head, count = 0; temp->next != NULL; temp = temp->next, count++)
		;

	return (count + 1);
}

void insert()
{
	int choice, data, position;
	struct NODE *temp, *p;

	printf("\n 1. Insertion at the beginning\n 2. Insertion at the End\n 3. Insertion before a node\n 4. Insertion after a node\n 5. Insertion at a given position\n");
	printf("Enter the number of your choice : ");
	scanf("%d", &choice);

	printf("\nEnter data : ");
	scanf("%d", &data);

	switch (choice)
	{
	case 1:
		// Insertion at the beginning
		insertAtPosition(data, 0);

		printf("\n>> Node inserted successfully at the beginning of the list <<\n\n");
		break;

	case 2:
		// Insertion at the End
		insertAtPosition(data, countNumberOfNodes() + 1);
		printf("\n>> Node inserted successfully at the end of the list <<\n\n");

		break;

	case 3:
		printf("\nEnter the node before which you want to insert the new node : ");
		scanf("%d", &position);

		insertAtPosition(data, position - 1);

		printf("\n>> Node inserted successfully before Node %d <<\n\n", position);
		break;

	case 4:
		printf("\nEnter the node after which you want to insert the new node : ");
		scanf("%d", &position);

		insertAtPosition(data, position + 1);

		printf("\n>> Node inserted successfully after Node %d <<\n\n", position);
		break;

	case 5:
		printf("\nEnter the position at which you want to insert the new node : ");
		scanf("%d", &position);

		insertAtPosition(data, position);

		printf("\n>> Node inserted successfully at Node %d <<\n\n", position);
		break;
	}
}

void insertAtPosition(int data, int position)
{
	struct NODE *temp, *p;
	int i;

	temp = (struct NODE *)malloc(sizeof(struct NODE));

	temp->data = data;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}
	else if (position == 0)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		for (p = head, i = 1; i < position - 1; p = p->next, i++)
			;

		temp->next = p->next;
		p->next = temp;
	}
}

void search()
{
	struct NODE *temp;
	int item, flag = 0, count;

	if (head == NULL)
	{
		printf("\n\t!!! LINKED LIST IS EMPTY. NOTHING TO SEARCH !!!\n\n");
		return;
	}

	printf("\nEnter the element you want to search : ");
	scanf("%d", &item);

	printf("\nSearching for %d...\n\n", item);

	for (temp = head, count = 1; temp->next != NULL; temp = temp->next, count++)
	{
		if (temp->data == item)
		{
			printf("  >> Item %d found in Node %d <<\n", item, count);
			flag = 1;
		}
	}

	if (temp->data == item)
	{
		printf(">> Item %d found in Node %d <<\n", item, count);
	}
	else if (flag == 0)
	{
		printf("!!! Item %d not found in the List !!!\n", item);
	}
}

/*
	OUTPUT:

	---- SINGLE LINEAR LINKED LIST ----

	 0. Exit
	 1. Create
	 2. Displaty
	 3. Count
	 4. Insertion
	 5. Deletion
	 6. Search
	 7. Sort
	 8. Reverse

	Enter the corresponding number of your choice : 1

	-: LINKED LIST CREATION :-
	How many nodes you want to create : 2

	Enter value for node 1 : 10

	Enter value for node 2 : 20

	>> The Linked List initialized successfully with 2 nodes <<


	Enter the corresponding number of your choice : 2

	LINKED LIST:

	 HEAD -> | 10 | 20 | -> NULL


	Press Enter to Continue...


	Enter the corresponding number of your choice : 3

	>> NUMBER OF NODES IN THE LIST IS : 2 <<

	Press Enter to Continue...


	Enter the corresponding number of your choice : 4

	LINKED LIST:

	 HEAD -> | 10 | 20 | -> NULL


		-: NODE INSERTION :-

	 1. Insertion at the beginning
	 2. Insertion at the End
	 3. Insertion before a node
	 4. Insertion after a node
	 5. Insertion at a given position

	Enter the number of your choice : 1

	Enter data : 5

	>> Node inserted successfully at the beginning of the list <<
	LINKED LIST:

	 HEAD -> | 5 | 10 | 20 | -> NULL


	Press Enter to Continue...

	Enter the corresponding number of your choice : 4

	LINKED LIST:

	 HEAD -> | 5 | 10 | 20 | -> NULL


		-: NODE INSERTION :-

	 1. Insertion at the beginning
	 2. Insertion at the End
	 3. Insertion before a node
	 4. Insertion after a node
	 5. Insertion at a given position

	Enter the number of your choice : 2

	Enter data : 25

	>> Node inserted successfully at the end of the list <<
	
	LINKED LIST:

	 HEAD -> | 5 | 10 | 20 | 25 | -> NULL

	Press Enter to Continue...

	Enter the corresponding number of your choice : 4

	LINKED LIST:

	 HEAD -> | 5 | 10 | 20 | 25 | -> NULL


		-: NODE INSERTION :-
	
	 1. Insertion at the beginning
	 2. Insertion at the End
	 3. Insertion before a node
	 4. Insertion after a node
	 5. Insertion at a given position

	Enter the number of your choice : 3

	Enter the node before which you want to insert the new node : 3

	Enter data : 15

	>> Node inserted successfully before Node 3 <<
	
	LINKED LIST:

	 HEAD -> | 5 | 10 | 15 | 20 | 25 | -> NULL

	Press Enter to Continue...


	Enter the corresponding number of your choice : 4

	LINKED LIST:

	 HEAD -> | 5 | 10 | 15 | 20 | 25 | -> NULL

		-: NODE INSERTION :-
	
	 1. Insertion at the beginning
	 2. Insertion at the End
	 3. Insertion before a node
	 4. Insertion after a node
	 5. Insertion at a given position

	Enter the number of your choice : 4

	Enter the node after which you want to insert the new node : 3

	Enter data : 47

	>> Node inserted successfully after Node 3 <<
	
	LINKED LIST:

	 HEAD -> | 5 | 10 | 15 | 47 | 20 | 25 | -> NULL

	Press Enter to Continue...

	Enter the corresponding number of your choice : 4

	LINKED LIST:

	 HEAD -> | 5 | 10 | 15 | 47 | 20 | 25 | -> NULL


		-: NODE INSERTION :-

	 1. Insertion at the beginning
	 2. Insertion at the End
	 3. Insertion before a node
	 4. Insertion after a node
	 5. Insertion at a given position

	Enter the number of your choice : 5

	Enter the position at which you want to insert the new node : 4

	Enter data : 100

	>> Node inserted successfully at Node 4 <<
	
	LINKED LIST:

	 HEAD -> | 5 | 10 | 15 | 100 | 47 | 20 | 25 | -> NULL

	Press Enter to Continue...

	Enter the corresponding number of your choice : 0

		 THANK YOU FOR USING THIS PROGRAM

*/
