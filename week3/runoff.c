#include "cs50.h"
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];
int voter_count;
int candidate_count;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");

        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);

        return 2;
    }

    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        candidates[candidate_number].name = argv[candidate_number + 1];
        candidates[candidate_number].votes = 0;
        candidates[candidate_number].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");

    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);

        return 3;
    }

    for (int voter_number = 0; voter_number < voter_count; voter_number++)
    {
        for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
        {
            string name = get_string("Rank %i: ", candidate_number + 1);

            if (!vote(voter_number, candidate_number, name))
            {
                printf("Invalid vote.\n");

                return 4;
            }
        }

        printf("\n");
    }

    while (true)
    {
        tabulate();

        bool won = print_winner();
    
        if (won) return 0;

        int min = find_min();
        bool tie = is_tie(min);

        if (tie)
        {
            for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
            {
                if (!candidates[candidate_number].eliminated)
                {
                    printf("%s\n", candidates[candidate_number].name);
                }
            }

            return 0;
        }

        eliminate(min);

        for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
        {
            candidates[candidate_number].votes = 0;
        }
    }

    return 0;
}

bool vote(int voter, int rank, string name)
{
    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        if (strcmp(candidates[candidate_number].name, name) == 0)
        {
            preferences[voter][rank] = candidate_number;

            return true;
        }
    }

    return false;
}

void tabulate(void)
{
    int first_vote;

    for (int voter_number = 0; voter_number < voter_count; voter_number++)
    {
        for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
        {
            first_vote = preferences[voter_number][candidate_number];

            if (!candidates[first_vote].eliminated)
            {
                candidates[first_vote].votes++;
                break;
            }
        }
    }

    return;
}

bool print_winner(void)
{
    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        if (candidates[candidate_number].votes > (voter_count/2))
        {
            printf("%s \n", candidates[candidate_number].name);

            return true;
        }
    }

    return false;
}

int find_min(void)
{
    int min_votes = voter_count;

    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        if (candidates[candidate_number].votes < min_votes && !candidates[candidate_number].eliminated) min_votes = candidates[candidate_number].votes;
    }

    return min_votes;
}

bool is_tie(int min)
{
    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        if (!candidates[candidate_number].eliminated && candidates[candidate_number].votes != min) return false;
    }

    return true;
}

void eliminate(int min)
{
    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        if (candidates[candidate_number].votes == min) candidates[candidate_number].eliminated = true;
    }

    return;
}
