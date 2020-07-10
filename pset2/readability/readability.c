#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to input text
    string text = get_string("Text: ");

    // initialize variables
    int char_count = 0;
    int word_count = 1;
    int sentence_count = 0;

    // count words
    for (int i = 0; i < strlen(text); i += 1)
    {
        // add to character count
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            char_count += 1;
        }
        // add to sentence count
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count += 1;
        }
        // add to word count
        else if (text[i] == ' ')
        {
            word_count += 1;
        }
    }

    /*
    Test the word / letter / sentence count:
    printf("Chars: %i\nWords: %i\nSentences: %i\n", char_count, word_count, sentence_count);
    */

    float grade = 0.0588 * (100 * (float) char_count / word_count) - 0.296 * (100 * (float) sentence_count / word_count) - 15.8;

    // return grade depending on text score
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}