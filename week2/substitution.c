#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// cc substitution.c -o substitution cs50.c
bool compare_text(char[]);
char rotate(char, char[]);

int main(int argc, string argv[]) 
{
    if (argc == 2)
    {
        char * key = argv[1];
        int key_length = strlen(key);
        int count = 0;

        for (int i = 0; i < 26; i++)
        {
            if (isalpha(key[i]) == 1)
            {
                count++;
            }

        }

        if (argc == 2 && key_length == 26 && count == 26 && compare_text(key) == true)
        {
            char new_code[10000];
            string text = get_string("plaintext: ");
            char * code = text;
            printf("ciphertext: ");

            for (int n = 0; n < strlen(code); n++)
            {
                new_code[n] = rotate(code[n], key);
            }

            for (int k = 0; k < strlen(new_code); k++)
            {
                printf("%c", new_code[k]);
            }

        printf("\n");
        return 0;    
        } 
        else 
        {
            printf("Key must contain 26 letters. Each letter can be used only once. \n");
            return 1;
        }
    } 
    else 
    {
        printf("./substitution key \n");
        return 1;
    }
}

bool compare_text(char text[])
{
    bool compare;

    for (int i = 0; i <= 26; i++)
    {
        for (int j = i + 1; j <= 26 - i; j++)
        {
            if (text[i] == text[j])
            {
                compare = false;
                break;
            } 
            else
            {
                compare = true;
            }
        }

        if (compare == false)
        {
            break;
        }
    }

    if (compare == false)
    {
        return false;
    } 
    else 
    {
        return true;
    }
}

char rotate(char text_r, char key_r[])
{
    char upper_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char new;
    int swap = text_r;
    int count = 0;

    if (swap <= 64 || swap >= 91 && swap <= 96 || swap >= 123)
    {
        new = text_r;
    } 
    else
    {
        if (islower(text_r) == 1)
        {
            for (int i = 0; i <= 26; i++)
            {
                if (text_r == lower_alphabet[i])
                {
                    break;
                }
                count ++;

            }

            new = tolower(key_r[count]);
        } 
        else 
        {
            for (int i = 0; i <= 26; i++)
            {
                if (text_r == upper_alphabet[i])
                {
                    break;
                }

                count ++;
            }

            new = toupper(key_r[count]);
        }
    }
    return new;
}
    