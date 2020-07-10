from sys import argv, exit
import itertools
import csv
import re


# check arguments
if len(argv) != 3:
    print('Please pass the right amount of arguments. Correct format is `python dna.py people.csv sequence.txt`.')
    exit(1)

# open CSV file
with open(argv[1], 'r') as csv_file:
    reader = list(csv.reader(csv_file))
    reader[0].remove("name")
    segment = reader[0]

#Open sequence TXT file
with open(argv[2],'r') as sequence:
    data = sequence.read()

value_list = []

# Scan the DNA file
for i in range(len(segment)):
    # Initialize variables
    maximum = 0
    counter = 0
    position = 0
    previous = 0

    while position < len(data):
        # determine position where segment is found
        position = data.find(segment[i], position)

        # if segment not found, reset counter
        if position == -1:
            counter = 0
            break

        # segment was found as first occurrence
        elif (position != -1) and previous == 0:
            counter += 1
            maximum = counter
            previous = position

        # segment occurs sequential
        elif (position != -1) and ((position - len(segment[i])) == previous):
            counter += 1
            previous = position
            if maximum < counter:
                maximum = counter

        # found first occurrence after start of sequence
        elif (position != -1) and ((position - len(segment[i])) != previous):
            counter = 1
            previous = position
            if maximum < counter:
                maximum = counter
        position += 1

    # append largest found occurrence
    value_list.append(maximum)

# compare occurrences of nucleotides to databases
value_list = list(map(str, value_list))

updated_list = list(reader)
updated_list.pop(0)

# compare value_list with reader
for person in updated_list:
    # if successful print persons name to the console
    if person[1:] == value_list:
        print(f'{person[0]}')
        break

    # No matches found
    elif person == updated_list[-1]:
        print('No match')