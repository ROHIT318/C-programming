#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Creating structure
typedef struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
}node;

node *root = NULL,*temp1 = NULL,*temp2 = NULL;

void create_bst(int data)
{
    if(root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->data = data;
        root->right = NULL;
        root->left = NULL;
        temp1 = root;
    }
    else if(root != NULL)
	{
		if((temp1->data) > data)
        {
    		printf("\nCHECK LESS.");
            printf("GO LEFT.\n");
            temp2 = temp1;
            temp1 = temp1->left;
            if(temp1 == NULL)
            {
          	    node *newtemp;
          	    newtemp = (node*)malloc(sizeof(node));
          	    temp2->left = newtemp;
          	    newtemp->data = data;
            	newtemp->left = NULL;
          	    newtemp->right = NULL;
          	    return;
            }
            else if(temp1 != NULL)
            {
                create_bst(data);
          	    return;
            }
        }
    	else if((temp1->data) < data)
    	{
    	    printf("\nCHECK GREATER."); 
    	    printf("GO RIGHT.\n"); 
      	    temp2 = temp1;
      	    temp1 = temp1->right;
      	    if(temp1 == NULL)
      	    {
      	        node *newtemp = (node*)malloc(sizeof(node));
      	        newtemp->data = data;
      	        newtemp->right = NULL;
      	        newtemp->left = NULL;
      	        temp2->right = newtemp;
      	        return;
      	    }
      	    else if(temp1 != NULL)
      	    {
      	        create_bst(data);
      	        return;
      	    }
    	}
    }
}


/*--------------x-------------x-----------End of BST creation------x-------------x-------------*/


/*------------------------------Start of Recursive BST or Tree traversal----------------------*/

// Inoreder traversal in BST
void inOrder(node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

// Post oreder traversal in BST
void postOrder(node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

// Pre oreder traversal in BST
void preOrder(node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//---------------------x-----------------x--------END of recursive BST or Tree traversal---------x-------------x-----------*/

// Function to count number of leaf nodes
int countLeaf(node *root)
{
	if(root == NULL)
	{
		return 1;	
	}	
	return countLeaf(root->left)+countLeaf(root->right);
}


// Main function
int main()
{
    // Initialisation of variables
    int data;

    // Creating BST and taking input.
    while(data != -999)
    {
        printf("Enter the data and -999 to end:");
        scanf("%d",&data);

        if(data==-999)
            break;
        
        temp1 = temp2 = root;
        create_bst(data); 
    }

    printf("\nInorder traversal:");
    inOrder(root);
    printf("\nPostorder traversal:");
    postOrder(root);
    printf("\nPreorder traversal:");
    preOrder(root);

    getch();
    return 0;
}
