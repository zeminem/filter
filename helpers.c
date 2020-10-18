#include "helpers.h"
#include <math.h>
#include <stdio.h>

#define MAX_VALUE 255.00

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            //RGBTRIPLE pixel_index = image[h][w];
            float average_rgb = (image[h][w].rgbtBlue + image[h][w].rgbtRed + image[h][w].rgbtGreen) / 3.00;
            int round_average = round(average_rgb);

            //printf("%d \n", pixel_index.rgbtBlue);
            image[h][w].rgbtBlue = round_average;
            image[h][w].rgbtGreen = round_average;
            image[h][w].rgbtRed = round_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            int sepiaRed = round(.393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue);
            int sepiaGreen = round(.349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue);
            int sepiaBlue = round(.272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue);

            //float maxValue = 255;

            image[h][w].rgbtRed = (sepiaRed > MAX_VALUE) ? MAX_VALUE : sepiaRed;
            image[h][w].rgbtGreen = (sepiaGreen > MAX_VALUE) ? MAX_VALUE : sepiaGreen;
            image[h][w].rgbtBlue = (sepiaBlue > MAX_VALUE) ? MAX_VALUE : sepiaBlue;

            // if (sepiaRed > MAX_VALUE)
            // {
            //     image[h][w].rgbtRed = MAX_VALUE;
            // }
            // if (sepiaGreen > MAX_VALUE)
            // {
            //     image[h][w].rgbtGreen = MAX_VALUE;
            // }
            // if (sepiaBlue > MAX_VALUE)
            // {
            //     image[h][w].rgbtBlue = MAX_VALUE;
            // }
            // if (sepiaRed < MAX_VALUE)
            // {
            //     image[h][w].rgbtRed = round(sepiaRed);
            // }
            // if (sepiaGreen < MAX_VALUE)
            // {
            //     image[h][w].rgbtGreen = round(sepiaGreen);
            // }
            // if (sepiaBlue < MAX_VALUE)
            // {
            //     image[h][w].rgbtBlue = round(sepiaBlue);
            // }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for(int w = 0; w < (width / 2); w++)
        {
            int temp_red = image[h][w].rgbtRed;
            int temp_green = image[h][w].rgbtGreen;
            int temp_blue = image[h][w].rgbtBlue;


            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;

            image[h][width - w - 1].rgbtRed = temp_red;
            image[h][width - w - 1].rgbtGreen = temp_green;
            image[h][width - w - 1].rgbtBlue = temp_blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}