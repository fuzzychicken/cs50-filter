#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j ++)
        {
            float avg = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            int r_avg = round(avg);

            image[i][j].rgbtBlue = r_avg;
            image[i][j].rgbtGreen = r_avg;
            image[i][j].rgbtRed = r_avg;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j ++)
        {

            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            int r_sepiaRed = round(sepiaRed);
            int r_sepiaGreen = round(sepiaGreen);
            int r_sepiaBlue = round(sepiaBlue);

            if (r_sepiaRed >= 255)
            {
                r_sepiaRed = 255;
            }

            if (r_sepiaGreen >= 255)
            {
                r_sepiaGreen = 255;
            }

            if (r_sepiaBlue >= 255)
            {
                r_sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = r_sepiaBlue;
            image[i][j].rgbtGreen = r_sepiaGreen;
            image[i][j].rgbtRed = r_sepiaRed;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
   RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width); j++)
        {
            temp[i][(width - 1) - j] = image[i][j];

        }

        for (int j = 0; j < (width); j++)
        {
            image[i][j] = temp[i][j];

        }
    }

    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)

        {
            if (i == (height - 1) && j == 0)

            {
                float avgB = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue) / 4.0;
                float avgG = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen) / 4.0;
                float avgR = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed) / 4.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }

            else if (i == (height - 1) && j == (width - 1))
            {
                float avgB = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue) / 4.0;
                float avgG = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen) / 4.0;
                float avgR = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed) / 4.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }

            else if (i == 0 && j == 0)
            {
                float avgB = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 4.0;
                float avgG = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 4.0;
                float avgR = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 4.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }
            else if (i == 0 && j == (width-1))

            {
                float avgB = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue) / 4.0;
                float avgG = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen) / 4.0;
                float avgR = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed) / 4.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }
            else if ((i > 0 && i < (height - 1)) && j == 0)
            {
                float avgB = (image[i][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue) / 6.0;
                float avgG = (image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen) / 6.0;
                float avgR = (image[i][j].rgbtRed + image[i+1][j].rgbtRed + image[i-1][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j+1].rgbtRed + image[i-1][j+1].rgbtRed) / 6.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }
            else if ((i > 0 && i < (height - 1)) && j == (width - 1))
            {
                float avgB = (image[i][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue) / 6.0;
                float avgG = (image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen) / 6.0;
                float avgR = (image[i][j].rgbtRed + image[i+1][j].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j-1].rgbtRed + image[i-1][j-1].rgbtRed) / 6.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }
            else if ((i == (height - 1)) && ((j > 0 && j < (width - 1))))
            {
                float avgB = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue) / 6.0;
                float avgG = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen) / 6.0;
                float avgR = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i-1][j-1].rgbtRed) / 6.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }
            else if ((i == 0) && ((j > 0 && j < (width - 1))))


            {
                float avgB = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue) / 6.0;
                float avgG = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen) / 6.0;
                float avgR = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i+1][j-1].rgbtRed) / 6.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }
            else
            {
                float avgB = (image[i][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue) / 9.0;
                float avgR = (image[i][j].rgbtRed + image[i+1][j].rgbtRed + image[i-1][j].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i+1][j+1].rgbtRed + image[i+1][j-1].rgbtRed) / 9.0;
                float avgG = (image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen) / 9.0;
                int r_avgB = round(avgB);
                int r_avgR = round(avgR);
                int r_avgG = round(avgG);

                temp[i][j].rgbtBlue = r_avgB;
                temp[i][j].rgbtGreen = r_avgG;
                temp[i][j].rgbtRed = r_avgR;
            }


        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}



