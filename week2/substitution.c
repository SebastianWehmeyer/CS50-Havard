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
        int number_of_letters = 0;

        for (int key_element = 0; key_element < key_length; key_element++)
        {
            if (isalpha(key[key_element]) == 1)
            {
                number_of_letters++;
            }

        } 

        if (argc == 2 && key_length == 26 && number_of_letters == 26 && compare_text(key) == true)
        {
            string input_text = get_string("plaintext: ");
            char * normal_text_as_char = input_text;
            char coded_text[strlen(normal_text_as_char)];
            printf("ciphertext: ");

            for (int text_element = 0; text_element < strlen(normal_text_as_char); text_element++)
            {
                coded_text[text_element] = rotate(normal_text_as_char[text_element], key);
            }

            for (int coded_element = 0; coded_element < strlen(coded_text); coded_element++)
            {
                printf("%c", coded_text[coded_element]);
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

bool compare_text(char key[])
{
    bool each_letter_once;

    for (int key_element = 0; key_element <= 26; key_element++)
    {
        for (int next_key_element = key_element + 1; next_key_element <= 26 - key_element; next_key_element++)
        {
            if (key[key_element] == key[next_key_element])
            {
                each_letter_once = false;
                break;
            } 
            else
            {
                each_letter_once = true;
            }
        }

        if (each_letter_once == false)
        {
            break;
        }
    }

    if (each_letter_once == false)
    {
        return false;
    } 
    else 
    {
        return true;
    }
}

char rotate(char normal_character, char key[])
{
    char upper_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char coded_character;
    int character_as_ascii = normal_character;
    int key_element = 0;

    if (character_as_ascii <= 64 || character_as_ascii >= 91 && character_as_ascii <= 96 || character_as_ascii >= 123) //If not a letter
    {
        coded_character = normal_character;
    } 
    else
    {
        if (islower(normal_character) == 1)
        {
            for (int alphabet_element = 0; alphabet_element <= 26; alphabet_element++)
            {
                if (normal_character == lower_alphabet[alphabet_element])
                {
                    break;
                }

                key_element++;
            }

            coded_character = tolower(key[key_element]);
        } 
        else 
        {
            for (int alphabet_element = 0; alphabet_element <= 26; alphabet_element++)
            {
                if (normal_character == upper_alphabet[alphabet_element])
                {
                    break;
                }

                key_element++;
            }

            coded_character = toupper(key[key_element]);
        }
    }
    return coded_character;
}
