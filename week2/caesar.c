#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// cc caesar.c -o caesar cs50.c
char caesar(char, int);

int main(int argc, string argv[]) 
{
    if (argc == 2)
    {
        int times_to_rotate = atoi(argv[1]);

        if (argc == 2 && times_to_rotate> 0)
        {
            
            string input_text = get_string("plaintext: ");
            char * normal_text_as_char = input_text;
            char chiffre_code[strlen(normal_text_as_char)];
            printf("ciphertext: ");

            for (int text_element = 0; text_element < strlen(normal_text_as_char); text_element++)
            {  
                chiffre_code[text_element] = caesar(normal_text_as_char[text_element], times_to_rotate);
            }

            for (int print_chiffre_element = 0; print_chiffre_element < strlen(chiffre_code); print_chiffre_element++)
            {
                printf("%c", chiffre_code[print_chiffre_element]);
            }

        printf("\n");
        } 
        else
        {
            printf("./caesar key \n");
            return 1;

        }
    } 
    else
    {
        printf("./caesar key \n");

        return 1;
    }
}

char caesar (char normal_character, int times_to_rotate)
{
    char chiffre_character;
    int character_as_ascii = normal_character;

    if (!isalpha(normal_character)) chiffre_character = normal_character;

    else
    {
        for (int number_of_rotations = 0; number_of_rotations < times_to_rotate; number_of_rotations++)
        {
            if (character_as_ascii == 90 || character_as_ascii == 122) character_as_ascii -= 26;  

            character_as_ascii++;
        }

        chiffre_character = character_as_ascii;
    }

    return chiffre_character;
}
