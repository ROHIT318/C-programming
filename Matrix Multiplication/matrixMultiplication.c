#include <stdio.h>
#include <conio.h>
 
int main()
{
    int row1,column1,row2,column2,i,j,k,sum = 0;
    int first[10][10], second[10][10], final[10][10];
 
    printf("Enter number of rows and columns of first matrix:");
    scanf("%d %d", &row1, &column1);
    printf("Enter elements of first matrix\n");
 
    for (i = 0;i < row1;i++)
    {
        for (j = 0;j < column1;j++)
        {
            scanf("%d", &first[i][j]);
        }
    }
 
    printf("Enter number of rows and columns of second matrix:");
    scanf("%d %d",&row2,&column2);
 
    if (column1 != row2)
    {
        printf("The matrices can't be multiplied with each other.");
    }
    else
    {
        printf("Enter elements of second matrix\n");
 
        for (i = 0;i < row2;i++)
        {
            for (j = 0;j < column2;j++)
            {
                scanf("%d", &second[i][j]);
            }
        }
 
        for (i = 0;i < row1;i++)
        {
            for (j = 0;j < column2;j++)
            {
                for (k = 0;k < row2;k++)
                {
                    sum = sum + first[i][k]*second[k][j];
                }
            final[i][j] = sum;
            sum = 0;
            }
        }
 
        printf("Product of the matrices:\n");
 
        for (i = 0;i < row1;i++)
        {
            for (j = 0;j < column2;j++)
            {
                printf("%d\t",final[i][j]);
                printf("\n");
            }
        }
    }

    getch();
    return 0;
}