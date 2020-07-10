#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to input their name
    string name = get_string("What's your name?\n");

    // Return string with their name
    printf("hello, %s\n", name);
}