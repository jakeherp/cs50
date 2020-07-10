from cs50 import get_int


def mario():
    # prompt user to input desired height
    height = get_int('Height: ')

    # if height is smaller than 1 or larger than 8 reprompt
    if height < 1 or height > 8:
        mario()
    else:
        for blocks in range(1, height + 1):
            spaces = height - blocks

            # print leading spaces
            print(" " * spaces, end="")
            # print first set of blocks
            print("#" * blocks, end="")
            # print space in between
            print("  ", end="")
            # print second set of blocks
            print("#" * blocks)


# run function initally
mario()