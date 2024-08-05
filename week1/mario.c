#include <stdio.h>

int main(void) 
{
    int rows;
    int height;

    do 
    {
        printf("Height: ");
        scanf("%d", &rows);
    } while (rows < 1 || rows > 8);
                                                    
    height = rows;

    for (int row_count = 1; row_count < (rows+1); row_count++) 
    {
        for (int times_to_print_left = 1; times_to_print_left < (rows+1); times_to_print_left++) 
        {
            if (times_to_print_left <= (rows - row_count)) printf(" ");

            else printf("#");
        }

        printf("  ");

        for (int times_to_print_right = 1; times_to_print_right <= (rows - (height-1)); times_to_print_right++) 
        {
            printf("#");
        }

        printf("\n");
        height -= 1;
    }
}
