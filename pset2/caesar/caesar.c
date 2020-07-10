#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // check that the argument was given correctly, otherwise return with error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argc != 2 || !isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // get key given
    int key = atoi(argv[1]);

    // get plain text input
    string plain = get_string("plaintext:  ");
    printf("ciphertext: ");

    // iterate over text input
    for (int i = 0; i < strlen(plain); i += 1)
    {
        // check if current character is a lowercase letter
        if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            char cipher_char = (((plain[i] - 'a') + key) % 26) + 'a';
            printf("%c", cipher_char);
        }
        // check if current character is an uppercase letter
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            char cipher_char = (((plain[i] - 'A') + key) % 26) + 'A';
            printf("%c", cipher_char);
        }
        // otherwise return the char unchanged
        else
        {
            printf("%c", plain[i]);
        }
    }

    printf("\n");
    return 0;
}