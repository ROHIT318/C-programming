#include <stdio.h>
#include <stdlib.h>
#include <conio.h>>

// Structure for creating list
typedef struct linkedList
{
	int data;
	struct linkedList *next;
}node;

node *head = NULL;

// Function for creating node
node *getNode(int x)
{
	node *ptr = (node*)malloc(sizeof(node));
	ptr->data = x;
	ptr->next = NULL;
	return (ptr);
}

// Function for creating list
void createList()
{
	int element;

	while(element != -999)
	{
		printf("Enter the element and -999 to end:");
		scanf("%d",&element);
		if(element == -999)
		{
			return;
		}
		node *ptr = getNode(element);
		node *ptr1;

		if(head == NULL)
		{
			head = ptr;
			ptr1 = head;
		}
		else if(head != NULL)
		{
			ptr1->next = ptr;
			ptr1 = ptr;
		}
	}
}

// Function for inserting node by position not by searching an element (working)
void insertNodeposition(int element,int position)
{
	if(position == 1)				// For inserting at beginning
	{
		node *ptr = getNode(element);
		ptr->next = head;
		head = ptr;
	}
	else if(position == -999)       // For inserting at end
	{
		node *ptr = head;

		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		node *ptr1 = getNode(element);
		ptr1->next = NULL;
		ptr->next = ptr1;
	}
	else if(position != -999 && position != 1)
	{
		node *ptr = head;

		int counter = 1;

		while(counter < position - 1)
		{
			ptr = ptr->next;
			counter++;
		}
		node *ptr1 = getNode(element);
		ptr1->next = ptr->next;
		ptr->next = ptr1;
	}
}

//Function to insert an element after a specific element by searching (working)
void insertAfter(int data,int element)
{
	node *ptr = head;
	while(ptr->data != data)
	{
		ptr = ptr->next;
	}
	node *nptr = getNode(element);
	nptr->next = ptr->next;
	ptr->next = nptr;
}

// Function to insert an element before a specific element by searching (working)
void insertBefore(int number,int element)
{
	node *ptr = head;
	node *nptr;

	while(ptr->data != number)
	{
		// printf("\n%d",ptr->data);
		if(ptr->data != number)
		{
			nptr = ptr;
		}
		ptr = ptr->next;
	}
	node *ptr1 = getNode(element);
	ptr1->next = nptr->next;
	nptr->next = ptr1;
}


// Function for deleting node by position not by searching element (working)
void deleteNode(int position)
{
	node *ptr = head;

	if(position == 1)
	{
		head = head->next;
	}
	else if(position == -999)
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
			ptr->next = NULL;
	}
	else if(position != 1 && position != -999)
	{
		int counter = 1;
		node *ptr = head,*nptr;
		while(counter < position - 1)
		{
			ptr = ptr->next;
			counter++;
		}
		nptr = ptr->next;
		ptr->next = nptr->next;
	}
}

// Function to delete a node of a particular data (working)
void deletedataNode(int data)
{
	node *ptr = head;
	node *nptr;

	while(ptr->data != data)
	{
		ptr = ptr->next;
		if(ptr->data != data)
		{
			nptr = ptr;
		}
	}
	nptr->next = ptr->next;
	if(head->data == data)
	{
		head = head->next;
	}
}

// Function for deleting an element after an element in the list(working)
void deleteAfter(int data)
{
	node *ptr = head;
	while(ptr->data != data)
	{
		ptr = ptr->next;
	}
	node *nptr = ptr->next;
	ptr->next = nptr->next;
}


// Function for deleting a node by position
void deleteBefore(int data)
{
	node *ptr = head,*nptr;
	
	if(ptr->data == data)
	{
		printf("No node present before it.");
		return;
	}
	
	while(ptr->next->data != data)
	{
		ptr = ptr->next;
	}
	data = ptr->data;
	
	ptr = head;
	while(ptr->next->data != data)
	{
		ptr = ptr->next;
	}
	nptr = ptr->next;
	ptr->next = nptr->next;
}


// Function to display list
void displayList()
{
	node *ptr;

	ptr = head;

	while(ptr != NULL)
	{
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
	if(ptr == NULL)
	{
		printf("NULL");
	}
}

int main()
{
	int element,position,x,data;

	createList();

	displayList();

	printf("\nFor insertion press 1");
	printf("\nFor deletion press 2");
	printf("\nEnter input:");
	scanf("%d",&x);

	switch(x)
	{
		case 1:
			printf("\nEnter the element to insert:");
			scanf("%d",&element);

			printf("\nFor inserting at beginning press 1");
			printf("\nFor inserting at some position or before or after element press 2");
			printf("\nFor inserting at end position press 3");
			printf("\nEnter input:");
			scanf("%d",&x);

			switch(x)
			{
				case 1:
					position = 1;
					insertNodeposition(element,position);
					displayList();
					break;
				case 2:
					printf("\nFor inserting data by position press 1");
					printf("\nFor inserting data after a data in list press 2");
					printf("\nFor inserting data before a data in list press 3");
					printf("Enter input:");
					scanf("%d",&x);
					switch (x)
					{
						case 1:
							printf("Enter the postion to insert:");
							scanf("%d",&position);
							//calling insertion function
							insertNodeposition(element,position);
							displayList();
							break;
						case 2:
							printf("\nEnter the data to search:");
							scanf("%d",&data);
							insertAfter(data,element);
							displayList();
							break;
						case 3:
							printf("\nEnter the data to search:");
							scanf("%d",&data);
							insertBefore(data,element);
							printf("\n");
							displayList();
							break;
						default:
							printf("Wrong input.");
					}
					break;
				case 3:
					insertNodeposition(element,-999);
					displayList();
					break;
				default:
					printf("Wrong input.");
					break;
			}
		break;
		case 2:
			printf("\nFor deleting the first element press 1.");
			printf("\nFor deleting the last element press 2.");
			printf("\nFor inserting at some position or before or after element press 3.");
			scanf("%d",&x);

			switch(x)
			{
			case 1:
				deleteNode(1);
				displayList();
				break;
			case 2:
				deleteNode(-999);
				displayList();
				break;
			case 3:
				printf("\nFor deleting data by position press 1");
				printf("\nFor deleting a particular data press 2.");
				printf("\nFor deleting data after a data in list press 3.");
				printf("\nFor deleting data before a data in list press 4.");
				scanf("%d",&x);
				switch (x)
				{
					case 1:
						printf("\nEnter the postion to delete:");
						scanf("%d",&position);
						//calling insertion function
						deleteNode(position);
						displayList();
						break;
					case 2:
						printf("\nEnter the data to delete:");
						scanf("%d",&data);
						deletedataNode(data);
						displayList();
						break;
					case 3:
						printf("\nEnter the data to delete element after that data:");
						scanf("%d",&data);
						deleteAfter(data);
						displayList();
						break;
					case 4:
						printf("\nEnter the data to delete element before that data:");
						scanf("%d",&data);
						deleteBefore(data);
						displayList();
						break;
					default:
						printf("Wrong input.");
				}
			}
	}
	getch(); 
	return 0;
}
