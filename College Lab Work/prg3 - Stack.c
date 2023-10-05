#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 4

void display();
void push();
void pop();
void peek();

int STACK[MAX_SIZE], TOP = -1;


int main() {
	int  choice;

	while (1) {

		printf("\n\t--: STACK OPERATIONS :--\n\n");
		printf(" 1. PUSH\n 2. POP\n 3. PEEK\n");
		printf(" 4. DISPLAY\n 0. Exit\n");
		printf("\nEnter corresponding numbers of your choice : ");
		scanf("%d", &choice);

		switch(choice) {
			case 0:
				printf("\n\tTHANK YOU FOR USING THE PROGRAM\n");
				exit(0);

			case 1:
				system("cls");
				printf("\n\t-- PUSH ELEMENT IN STACK --\n\n");

				push();

				break;

			case 2:
//				Deletion
				printf("\n\t-- POP ELEMENT FROM STACK --\n\n");

				pop();

				break;

			case 3:
//
				peek();

				break;

			case 4:

				display();

				break;

			default:
				printf("\n\t!!! ERROR: Wrong Choice !!!\t");
		}

		printf("\n\nPress Enter to continue.... ");
		fflush(stdin);
		getchar();
		system("cls");
	}



	printf("\n\nAfter calling all function, returned at main\n");

	return 0;
}

void display() {
	int i;

	if(TOP == -1) {
		printf("\n\t!!! STACK IS EMPTY !!!\n\n");
		return;
	}

	printf("\n\nThe STACK is : \n\n");

	for(i = TOP; i >= 0; i--) {
		printf("\n\t| %d |", STACK[i]);

		if(i == TOP) {
			printf(" <-- TOP");
		}
	}
}

void push() {
	int i, item;

	if(TOP == MAX_SIZE - 1) {
		printf("\n\t!!! STACK FULL. CAN'T INSERT NEW ELEMENT !!!\n\n");
		return;
	}

	printf("Enter a element : ");
	scanf("%d", &item);

	TOP = TOP + 1;

	STACK[TOP] = item;

	printf("\n>> New element %d succefully entered in the STACK <<\n", item);

	display();
}

void pop() {
	int i;

	if(TOP == - 1) {
		printf("\n !!! STACK EMPTY. CAN'T DELETE ANY ELEMENT !!!\n\n");
		return;
	}

	TOP = TOP - 1;

	printf("\n>> Top element %d succefully deleted from the STACK <<\n", STACK[TOP + 1]);

	display();
}

void peek() {
	if(TOP == - 1) {
		printf("\n !!! STACK EMPTY. CAN'T SHOW THE PEEK !!!\n\n");
		return;
	}

	printf("\n >> THE TOP OF THE STACK IS = %d at INDEX = %d << \n", STACK[TOP], TOP);
}




