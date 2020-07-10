from cs50 import get_int
from math import floor


# initialize variables
first_digit = 0
second_digit = 0
digits = 0
sum_odds = 0
sum_evens = 0

# Prompt user to input card number
card_number = get_int("Number: ")

while card_number > 0:
    second_digit = first_digit
    first_digit = card_number % 10

    if digits % 2 == 0:
        sum_evens += first_digit
    else:
        multiple = 2 * first_digit
        sum_odds += (multiple % 10) + (multiple // 10)

    card_number //= 10
    digits += 1

is_valid = (sum_evens + sum_odds) % 10 == 0
first_two = (first_digit * 10) + second_digit

if first_digit == 4 and digits >= 13 and digits <= 16 and is_valid:
    print("VISA\n")
elif first_two >= 51 and first_two <= 55 and digits == 16 and is_valid:
    print("MASTERCARD\n")
elif (first_two == 34 or first_two == 37) and digits == 15 and is_valid:
    print("AMEX\n")
else:
    print("INVALID\n")