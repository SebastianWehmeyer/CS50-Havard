#include <stdio.h>
#include <string.h>
#include "cs50.h"

float average(float, float);
int count_letters(char[]);
int count_words(char[]);
int count_sentences(char[]);

//cc readability.c -o readability cs50.c
int main(void) 
{
    string text = get_string("Text: ");
    char * text_c = text;
    float index = 0.0588 * (average(count_letters(text_c), count_words(text_c))) - 0.296 * (average(count_sentences(text_c), count_words(text_c))) - 15.8;
    int new_index = round(index);

    if (new_index >= 16) 
    {
        printf("Grade: 16+ \n");
    } 
    else if (index < 1) 
    {
        printf("Before Grade 1 \n");
    } 
    else 
    {
        printf("Grade: %d \n", new_index);
    }
}

float average(float avg, float f_words) 
{
    return (avg / f_words)*100;
}

int count_letters(char text[]) 
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++) 
    {
        if (text[i] != ' ' && text[i] != '.' && text[i] != '!' && text[i] != '?' && text[i] != ',' && text[i] != ';' && text[i] != '\'' && text[i] != ':' && text[i] != '-' && text[i] != '"') 
        {
            letters++;
        }
    }
    return letters;
}

int count_words(char text[]) 
{
    int words = 0;

    for (int i = 0; i < strlen(text); i++) 
    {
        if (text[i] == ' ' || text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == ',' || text[i] == ';' || text[i] == ':') 
        {
            if (text[i] == ' ') 
            {
                words++;
            } 
            else 
            {
                i++;
                words++;
            }
        }
    }
    return words;
}

int count_sentences(char text[]) 
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++) 
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') 
        {
            sentences++;
        }
    }
    return sentences;
}
