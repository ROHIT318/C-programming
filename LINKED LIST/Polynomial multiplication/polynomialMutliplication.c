#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 

typedef struct list
{
    int coeff; 
    int power; 
    struct list *next; 
}node; 

node *poly1 = NULL,*poly2 = NULL,*head = NULL; 

int main()
{
    node *temp1,*temp2,*newNode,*temp3; 
    int counter = 0,degree1,degree2,data,power,coeff; 

    printf("\n\n  Enter input for first equation"); 
    printf("\nEnter the degree of polynomial equation:"); 
    scanf("%d",&degree1); 


    for(counter = degree1;counter >= 0;counter--)
    {
        node *temp1 = (node*)malloc(sizeof(node)); 
        printf("Enter the co-effecient of X^%d:",counter);
        scanf("%d",&data); 
        temp1->coeff = data; 
        temp1->power = counter; 
        temp1->next = NULL;
        
        if(poly1 == NULL)
        {
            poly1 = temp1; 
            temp2 = temp1; 
        }
        else if(poly1 != NULL)
        {
            temp2->next = temp1; 
            temp2 = temp1; 
        }
    }


    printf("\n\n  Enter input for second equation"); 
    printf("\nEnter the degree of polynomial equation:"); 
    scanf("%d",&degree2); 
 

    for(counter = degree2;counter >= 0;counter--)
    {
        node *temp1 = (node*)malloc(sizeof(node)); 
        printf("Enter the co-effecient of X^%d:",counter);
        scanf("%d",&data); 
        temp1->coeff = data; 
        temp1->power = counter; 
       
        temp1->next = NULL;
        
        if(poly2 == NULL)
        {
            poly2 = temp1; 
            temp2 = temp1; 
        }
        else if(poly2 != NULL)
        {
            temp2->next = temp1; 
            temp2 = temp1; 
        }
    }

    printf("\n\n"); 
    printf("First equation is "); 
    temp1 = poly1; 
    for(counter = degree1;counter >= 0;counter--)
    {
        printf("%dX^%d ",temp1->coeff,temp1->power);
        if(counter != 0) 
            printf("+ "); 
        temp1 = temp1->next; 
    }

    printf("\n\n"); 
    printf("Second equation is "); 
    temp1 = poly2; 
    for(counter = degree2;counter >= 0;counter--)
    {
        printf("%dX^%d ",temp1->coeff,temp1->power);
        if(counter != 0) 
            printf("+ "); 
        temp1 = temp1->next; 
    }

    for(temp1 = poly1;temp1 != NULL;temp1 = temp1->next)
    {
        for(temp2 = poly2;temp2 != NULL;temp2 = temp2->next)
        {
            newNode = (node*)malloc(sizeof(newNode));
            coeff = (temp1->coeff)*(temp2->coeff); 
            power = (temp1->power)+(temp2->power); 
            newNode->coeff = coeff; 
            newNode->power = power; 
            newNode->next = NULL; 
            if(head == NULL)
            {
                head = newNode; 
                temp3 = head; 
            }
            else
            {
                temp3->next = newNode; 
                temp3 = newNode; 
            }
        }
    }

    printf("\n\nProduct = ");
    
    coeff = 0; 
    int highestPower = degree1 + degree2; 

    for(temp1 = head;temp1 != NULL && highestPower >= 0;temp1 = temp1->next)
    {
        for(temp2 = head;temp2 != NULL;temp2 = temp2->next)
        {
            if(temp2->power == highestPower)
                coeff += temp2->coeff; 
        }
        printf("%dX^%d",coeff,highestPower); 
        if(highestPower > 0) 
            printf("+ ");
        highestPower--; 
        coeff = 0; 
    }
    getch(); 
    return 0; 
}
