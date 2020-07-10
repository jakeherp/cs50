#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Initialize variable
    int cents = 0;

    // Prompt user to input the change owed
    do
    {
        // Prompt user to input their name
        float change = get_float("Change owed: ");
        cents = round(change * 100);
    }
    // Re-prompt user if change is less than or equal to 0
    while (cents <= 0);

    // Create a reusable variable of the rest of quarters
    int rest = cents % 25;

    // Calculate each coin
    int quarters = cents / 25;
    int dimes = rest / 10;
    int nickels = (rest % 10) / 5;
    int pennies = (rest % 10) % 5;

    // Return string with the total
    printf("%d\n", quarters + dimes + nickels + pennies);
}