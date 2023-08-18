#include "cs50.h"
#include <stdio.h>
#include <string.h>

#define MAX 9

int preferences[MAX][MAX];
bool locked[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
}
pair;

string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool has_cycle(int, int);

int main(int argc, string argv[]) //Main was predetermined
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");

        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);

        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    for (int candidate_winner = 0; candidate_winner < candidate_count; candidate_winner++)
    {
        for (int candidate_loser = 0; candidate_loser < candidate_count; candidate_loser++)
        {
            locked[candidate_winner][candidate_loser] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");

                return 3;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

bool vote(int rank, string name, int ranks[])
{
    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        if (strcmp(candidates[candidate_number], name) == 0)
        {
            ranks[rank] = candidate_number;

            return true;
        }
    } 

    return false;
}

void record_preferences(int ranks[])
{
    for (int rank = 0; rank < candidate_count; rank++)
    {
        for (int rank_after = rank+1; rank_after < candidate_count; rank_after++)
        {
            preferences[ranks[rank]][ranks[rank_after]]++;
        }
    }

    return;
}

void add_pairs(void)
{
    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        for (int candidate_after = candidate_number+1; candidate_after < candidate_count; candidate_after++)
        {
            if (preferences[candidate_number][candidate_after] > preferences[candidate_after][candidate_number])
            {
                pairs[pair_count].winner = candidate_number;
                pairs[pair_count].loser = candidate_after;
                pair_count++;
            }
            else if (preferences[candidate_number][candidate_after] < preferences[candidate_after][candidate_number])
            {
                pairs[pair_count].winner = candidate_after;
                pairs[pair_count].loser = candidate_number;
                pair_count++;
            }
        }
    }

    return;
}

void sort_pairs(void)
{
    for (int pair_count_minus_one = (pair_count -1); pair_count_minus_one >= 0; pair_count_minus_one--)
    {
        for (int pair_number = 0; pair_number <= pair_count_minus_one; pair_number++)
        {
            if ((preferences[pairs[pair_number].winner][pairs[pair_number].loser]) < (preferences[pairs[pair_number+1].winner][pairs[pair_number+1].loser]))  
            {
                pair temporary = pairs[pair_number];
                pairs[pair_number] = pairs[pair_number+1];
                pairs[pair_number+1] = temporary;
            }
        }
    }

    return;
}

void lock_pairs(void)
{
    for (int pair_number = 0; pair_number < pair_count; pair_number++)
    {
        bool cycle_exists = has_cycle(pairs[pair_number].loser, pairs[pair_number].winner);

        if(!cycle_exists) locked[pairs[pair_number].winner][pairs[pair_number].loser] = true;
    }

    return;
}

void print_winner(void)
{
    for(int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        int count = 0;

        for(int locked_winner = 0; locked_winner < candidate_count; locked_winner++)
        {
            if(!locked[locked_winner][candidate_number])
            {
                count++;

                if(count == candidate_count)
                {
                    printf("%s \n",candidates[candidate_number]);
                    return;
                }
            }
        }
    }

    return;
}

bool has_cycle(int cycle_end, int cycle_start)
{
    if (cycle_end == cycle_start) return true;

    for (int candidate_number = 0; candidate_number < candidate_count; candidate_number++)
    {
        bool locked_pair_exists = locked[cycle_end][candidate_number] && has_cycle(candidate_number, cycle_start);
        if(locked_pair_exists) return true;
    }

    return false;
}
