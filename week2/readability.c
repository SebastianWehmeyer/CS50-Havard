#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "cs50.h"

float average(float, float);
int count_letters(char[]);
int count_words(char[]);
int count_sentences(char[]);

//cc readability.c -o readability cs50.c
int main(void) 
{
    string input_text = get_string("Text: ");
    char * text_as_char = input_text;
    float index = 0.0588 * (average(count_letters(text_as_char), count_words(text_as_char))) - 0.296 * (average(count_sentences(text_as_char), count_words(text_as_char))) - 15.8;
    int round_index = round(index);

    if (round_index >= 16) 
    {
        printf("Grade: 16+ \n");
    } 
    else if (round_index < 1) 
    {
        printf("Before Grade 1 \n");
    } 
    else 
    {
        printf("Grade: %d \n", round_index);
    }
}

float average(float counted_letters_and_sentences, float counted_words) 
{
    return (counted_letters_and_sentences / counted_words)*100;
}

int count_letters(char text[]) 
{
    int letters = 0;

    for (int character = 0; character < strlen(text); character++) 
    {
        if(isalpha(text[character]) != 0) letters++;
    }

    return letters;
}

int count_words(char text[]) 
{
    int words = 0;

    for (int text_character = 0; text_character < strlen(text); text_character++) 
    {
        if (isalpha(text[text_character]) == 0 && text[text_character] == ' ') words++;
    }

    return words;
}

int count_sentences(char text[]) 
{
    int sentences = 0;

    for (int end_of_sentence = 0; end_of_sentence < strlen(text); end_of_sentence++) 
    {
        if (text[end_of_sentence] == '.' || text[end_of_sentence] == '?' || text[end_of_sentence] == '!') sentences++;
    }

    return sentences;
}
