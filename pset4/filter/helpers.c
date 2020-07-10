#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbtGrey;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Calculate average color in grey scale
            rgbtGrey = round((image[j][i].rgbtRed + image[j][i].rgbtGreen + image[j][i].rgbtBlue) / 3.0);

            // Replace color values with grey scale values
            image[j][i].rgbtRed = rgbtGrey;
            image[j][i].rgbtGreen = rgbtGrey;
            image[j][i].rgbtBlue = rgbtGrey;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red;
    int green;
    int blue;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Calculate color values for sepia
            red = round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue);
            green = round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue);
            blue = round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue);

            // Make sure the maximum value is 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            // replace color values with sepia values
            image[j][i].rgbtRed = red;
            image[j][i].rgbtGreen = green;
            image[j][i].rgbtBlue = blue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary array to store pixel values
    int temp[3];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;

            // swap pixel values
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtBlue = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtRed = temp[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int red;
    int green;
    int blue;

    float count;

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            red = 0;
            green = 0;
            blue = 0;

            count = 0.0;

            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    red += image[j + k][i + h].rgbtRed;
                    green += image[j + k][i + h].rgbtGreen;
                    blue += image[j + k][i + h].rgbtBlue;
                    count++;
                }
            }

            //takes average values for bur effect
            temp[j][i].rgbtRed = round(red / count);
            temp[j][i].rgbtGreen = round(green / count);
            temp[j][i].rgbtBlue = round(blue / count);
        }
    }

    //copies temporary values
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
        }
    }
}
