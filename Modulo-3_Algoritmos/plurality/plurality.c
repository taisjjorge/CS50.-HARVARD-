#include <stdio.h>
#include <string.h>
// Max number of candidates
#define MAX 9
// Candidates have name and vote count
typedef struct
{
    char name[100];
    int votes;
} candidate;
// Array of candidates
candidate candidates[MAX];
// Number of candidates
int candidate_count;
// Function prototypes
int vote(char *name);
void print_winner(void);
int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }
    int voter_count;
    printf("Number of voters: ");
    scanf("%i", &voter_count);
    // Clear input buffer
    while (getchar() != '\n')
        ;
    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[100];
        printf("Vote: ");
        fgets(name, sizeof(name), stdin);
        // Remove newline character from name
        name[strcspn(name, "\n")] = '\0';
        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner of election
    print_winner();
}
// Update vote totals given a new vote
int vote(char *name)
{
    // Iterate over the candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // If the name matches a candidate, increment their vote count and return true
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return 1;
        }
    }
    // If the name doesn't match any candidate, return false
    return 0;
}
// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;
    // Find the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }
    // Print the names of the candidates with the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}