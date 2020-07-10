#include <stdio.h>
#include <stdlib.h>

#define BUFFER 512

int main(int argc, char *argv[])
{
    // Check if correct arguments are provided
    if (argc != 2)
    {
        printf("Usage: recover file.raw\n");
        return 1;
    }

    // Open file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // create buffer
    unsigned char buffer[BUFFER];

    // counter for files
    int counter = 0;

    // initialize image
    FILE *image = NULL;

    // Did we find a JPG file yet?
    int jpg_found = 0;

    // read file
    while (fread(buffer, BUFFER, 1, input) == 1)
    {
        // read first 4 bytes and look for JPG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // if we find a new image, close the file
            if (jpg_found == 1)
            {
                fclose(image);
            }
            // set jpg_found to true so we can write the file
            else
            {
                jpg_found = 1;
            }

            char file_name[8];
            sprintf(file_name, "%03d.jpg", counter);
            image = fopen(file_name, "a");
            counter++;
        }

        if (jpg_found == 1)
        {
            fwrite(&buffer, BUFFER, 1, image);
        }
    }

    // cleanup
    fclose(input);
    fclose(image);

    return 0;
}
