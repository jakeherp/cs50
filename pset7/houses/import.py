from sys import argv, exit
from cs50 import SQL
from csv import reader

# load the database
db = SQL("sqlite:///students.db")

# check arguments
if len(argv) < 2:
    print("Usage: import.py characters.csv")
    exit()

# open CSV file
with open(argv[1], newline='') as characters_file:
    characters = reader(characters_file)
    for name in characters:
        if name[0] == 'name':
            continue

        # split the full name into first names and last name
        full_name = name[0].split()

        # insert data into database, pass NULL if no middle name exists
        if len(full_name) < 3:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       full_name[0], None, full_name[1], name[1], name[2])

        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       full_name[0], full_name[1], full_name[2], name[1], name[2])