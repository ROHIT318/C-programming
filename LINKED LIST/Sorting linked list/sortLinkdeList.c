#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Structure for creating list
typedef struct linkedList
{
	int data;
	struct linkedList *next;
}node;

node *head,*firstList,*secondList;

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

// Function to display list
void displayList(node *head)
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
    printf("\n");
}

/* Function to sort linkedList using bubble sort
void sortList(node *head)
{
    node *ptr1,*ptr2;
    int temp;

    for(ptr1 = head;ptr1->next != NULL;ptr1 = ptr1->next)
    {
        for(ptr2 = ptr1->next;ptr2 != NULL;ptr2 = ptr2->next)
        {
            if(ptr1->data > ptr2->data);
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
}*/

void sortList(node *start) 
{ 
    int swapped, i; 
    node *ptr1; 
    node *lptr = NULL; 
  
    // Checking for empty list 
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
// function to swap data of two nodes a and b
void swap(node *a, node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

// Main function
int main()
{
    node *temp;

    printf("Creating the first list:\n");
    createList();
    firstList = head;
    displayList(firstList);

    head = NULL;

    printf("\n\nCreating the second list:\n");
    createList();
    secondList = head;
    displayList(secondList);

    printf("\n\n");

    // Merging both lists into a single list
    temp = firstList;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = secondList;

    printf("List before Sorting:");
    displayList(firstList);

    // Calling function to sort list
    sortList(firstList);

    printf("List after Sorting:");
    displayList(firstList);

    getch();
}
