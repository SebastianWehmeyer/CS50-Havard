#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int N = 150000;
int words_in_dictionary = 0;
node *table[N];

bool check(const char *word)
{
    int hash_value = hash(word);
    node *n = table[hash_value];

    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

unsigned int hash(const char *word)
{
    int word_sum = 0;
    for (int text_character = 0; text_character < strlen(word); text_character++)
    {
        word_sum += toupper(word[text_character]);
    }

    return word_sum % N;
}

bool load(const char *dictionary)
{
    FILE *dictionary_pointer = fopen(dictionary, "r");

    if (dictionary == NULL)
    {
        printf("Could not open %s \n", dictionary);
        return false;
    }

    char next_word[LENGTH + 1];

    while (fscanf(dictionary_pointer, "%s", next_word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return 1;
        }

        strcpy(n->word, next_word);
        int hash_value = hash(next_word);

        n->next = table[hash_value];
        table[hash_value] = n;
        words_in_dictionary++;
    }

    fclose(dictionary_pointer);

    return true;
}

unsigned int size(void)
{
    if (words_in_dictionary == 0)
    {
        return 0;
    }
    else
    {
        return words_in_dictionary;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
