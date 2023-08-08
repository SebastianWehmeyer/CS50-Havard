#include <stdio.h>


int main(void) 
{
    int rows;
    int a;

    do 
    {
        printf("Height: ");
        scanf("%d", &rows);
    } while (rows < 1 || rows > 8);
                                                    
    a = rows;

    for (int i = 1; i < (rows+1); i++) 
    {
        for (int j = 1; j < (rows+1); j++) 
        {
            if (j <= (rows - i)) 
            {
                printf(" ");
            } else 
            {
                printf("#");
            }

        }

        printf("  ");

        for (int k = 1; k <= (rows - (a-1)); k++) 
        {
            printf("#");
        }

        printf("\n");
        a -= 1;
    }

}
