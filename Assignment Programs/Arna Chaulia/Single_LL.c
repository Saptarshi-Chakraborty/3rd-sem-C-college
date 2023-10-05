#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *head;

void create(int);
void display();
int count();
void search(int);

int main()
{
	int choice, item, size = 0;

	while (1)
	{

		printf("\n\t-: SINGLE LINKED LIST :-\n");
		printf(" 0. Exit\n 1. Create Single Linked List\n 2. Display the Linked List\n 3. Count number of nodes\n 4. Search for an item\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			exit(0);

		case 1:
			printf("\nHow many nodes you want to create : ");
			scanf("%d", &size);
			
			create(size);

			display();
			
			break;

		case 2:
			display();

			break;

		case 3:
			printf("\nThere are %d nodes in the Linked List\n", count());

			break;

		case 4:
		
			printf("\nEnter the item you want to search : ");
			scanf("%d", &item);

			display();
			search(item);

			break;

		default:
			printf("\n\t!!! Enter a correct choice !!!\t");
		}

		printf("\n\nPress Enter to continue...");
		fflush(stdin);
		getchar();
		// system("cls");
	}
	return 0;
}

void create(int size)
{
	struct node *newnode, *temp;
	int i, data;

	head = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter element 1 = ");
	scanf("%d", &data);

	head->data = data;
	head->next = NULL;

	temp = head;

	for (i = 2; i <= size; i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));

		printf("Enter element %d : ", i);
		scanf("%d", &data);

		newnode->data = data;
		newnode->next = NULL;

		temp->next = newnode;
		temp = temp->next;
	}
}

void display(){
	struct node *temp;
	
	temp = head;
	
	printf("\nThe Linked List is :\nHead -> ");

	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

int count(){
	struct node *temp;
	int count = 0;
	
	temp = head;
	
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	
	return count;
}

void search(int item){
	struct node *temp;
	int count = 1;
	
	temp = head;
	
	while(temp != NULL){
		if(temp->data == item){
			printf("\n%d found at position %d\n", item, count);
			return;
		}
		count++;
		temp = temp->next;
	}
	
	printf("\n%d not found in the Linked List\n", item);
}



/*
 
*/

