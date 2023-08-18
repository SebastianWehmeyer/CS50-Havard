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
    for row in range(1, len(database)):
        count = 0
        for column in range(1, len(database[0])):
            if int(database[row][column]) == matches[column - 1]:
                count += 1
                if count == len(database[0]) - 1:
                    print(database[row][0])
                    printed = True
                    break
    if not printed:
        print("No Match")

    return

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            
            else:
                break
        
        longest_run = max(longest_run, count)

    return longest_run

main()
