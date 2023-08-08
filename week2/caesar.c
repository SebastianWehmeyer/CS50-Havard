#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// cc caesar.c -o caesar cs50.c
char caesar(char, int);

int main(int argc, string argv[]) 
{
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        if (argc == 2 && key > 0)
        {
            char new_code[10000];
            string text = get_string("plaintext: ");
            char * code = text;
            printf("ciphertext: ");

            for (int n = 0; n < strlen(code); n++)
            {  
                new_code[n] = caesar(code[n], key);
            }

            for (int k = 0; k < strlen(new_code); k++)
            {
                printf("%c", new_code[k]);
            }
           
        printf("\n");

        } else
        {
            printf("./caesar key \n");
            return 1;
        }

    } else
    {
        printf("./caesar key \n");
        return 1;
    }

}


char caesar (char code_f, int key_f)
{
    char new;
    int rotate = code_f;
    if (code_f == ' ')
    {
        new = ' ';
    } else
    {
        for (int j = 0; j < key_f; j++)
        {
            if (rotate == 90 || rotate == 122)
            {
                rotate -= 26;  
            }

            rotate++;
        }
        new = rotate;
    }

    
    return new;
}