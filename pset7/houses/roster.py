from sys import argv
from cs50 import SQL

# check args
if len(argv) < 2:
    print("usage error, roster.py houseName")
    exit()

# load database
db = SQL("sqlite:///students.db")
students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last", argv[1])

# print each persons information
for student in students:
    if student['middle'] != None:
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")