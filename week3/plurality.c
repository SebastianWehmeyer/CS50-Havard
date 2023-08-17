#include "cs50.h"
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name);
void print_winner(void);

// cc plurality.c -o plurality cs50.c
int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");

        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);

        return 2;
    }

    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        candidates[candidate_number].name = argv[candidate_number + 1];
        candidates[candidate_number].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int voter_number = 0;voter_number < voter_count; voter_number++)
    {
        string name = get_string("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
}

bool vote(string name)
{
    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        if (strcmp(candidates[candidate_number].name, name) == 0)
        {
            candidates[candidate_number].votes++;

            return true;
        }
    }

    return false;
}

void print_winner(void)
{
    int max_votes = 0;
    string name;

    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        if (candidates[candidate_number].votes > max_votes)
        {
            max_votes = candidates[candidate_number].votes;
        }
    }

    for (int element = 0; element < candidate_count; element++)
    {
        if (candidates[element].votes == max_votes)
        {
            printf("%s \n", candidates[element].name);
        }
    }

    return;
}
