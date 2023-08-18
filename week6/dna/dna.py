import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Usage: python3 dna.py database.csv sequences.txt")
        exit()

    database_filename = sys.argv[1]
    sequence_filename = sys.argv[2]

    with open("databases/" + database_filename, "r") as csvfile:
        reader = csv.reader(csvfile)
        database = list(reader)
    
    with open("sequences/" + sequence_filename, "r") as file:
        sequence = file.read()

    matches = []

    for i in range(1, len(database[0])):
        matches.append(longest_match(sequence, database[0][i]))
    
    printed = False
    for i in range(1, len(database)):
        count = 0
        for j in range(1, len(database[0])):
            if int(database[i][j]) == matches[j - 1]:
                count += 1
                if count == len(database[0]) - 1:
                    print(database[i][0])
                    printed = True
                    break
    if not printed:
        print("No Match")

    return

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
