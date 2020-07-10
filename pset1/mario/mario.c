#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // If number meets criteria print the pyramid
    if (number > 0 || number < 9)
    {
        int count = 0;

        for (int row = 0; row < number; row += 1)
        {
            if (count != number)
            {
                // add leading whitespace
                for (int whitespace = (number - 1) - count; whitespace > 0; whitespace -= 1)
                {
                    printf(" ");
                }
                // add first set of blocks
                for (int block = 0; block <= count; block += 1)
                {
                    printf("#");
                }
                // add spaces in between blocks
                printf("  ");
                // add second set of blocks
                for (int block = 0; block <= count; block += 1)
                {
                    printf("#");
                }
                // add line break after one row is finished
                printf("\n");

                // increment count
                count += 1;
            }
        }
    }
}