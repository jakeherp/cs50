from cs50 import get_string
import re


# prompt user to input text
text = get_string('Text: ').split()

# initialize variables
letters = 0
words = 0
sentences = 0

# iterate over words
for word in text:
    # increment word count
    words += 1

    # count characters (letters + numbers) and increment letters
    filtered = re.sub('[^A-Za-z0-9]+', '', word)
    letters += len(filtered)

    # count sentences
    punctuations = ['.', '!', '?']
    if any(delimiter in word for delimiter in punctuations):
        sentences += 1

average = 100 / words
index = (0.0588 * letters * average) - (0.296 * sentences * average) - 15.8

# determine score
if index < 1:
    print('Before Grade 1')
elif index > 16:
    print('Grade 16+')
else:
    print(f'Grade {round(index)}')
