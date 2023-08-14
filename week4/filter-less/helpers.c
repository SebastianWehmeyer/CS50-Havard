#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int currentHeight = 0; currentHeight < height; currentHeight++)
    {
        for (int currentWidth = 0; currentWidth < width; currentWidth++)
        {
             int rgbt = round((image[currentHeight][currentWidth].rgbtBlue + image[currentHeight][currentWidth].rgbtGreen + image[currentHeight][currentWidth].rgbtRed) / 3);
             image[currentHeight][currentWidth].rgbtBlue = image[currentHeight][currentWidth].rgbtGreen = image[currentHeight][currentWidth].rgbtRed = rgbt;
        }
    }

    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int currentHeight = 0; currentHeight < height; currentHeight++)
    {
        for (int currentWidth = 0; currentWidth < width; currentWidth++)
        {
            int sepiaRed = round(.393 * image[currentHeight][currentWidth].rgbtRed + .769 * image[currentHeight][currentWidth].rgbtGreen + .189 * image[currentHeight][currentWidth].rgbtBlue);
            int sepiaGreen = round(.349 * image[currentHeight][currentWidth].rgbtRed + .686 * image[currentHeight][currentWidth].rgbtGreen + .168 * image[currentHeight][currentWidth].rgbtBlue);
            int sepiaBlue = round(.272 * image[currentHeight][currentWidth].rgbtRed + .534 * image[currentHeight][currentWidth].rgbtGreen + .131 * image[currentHeight][currentWidth].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
    
            image[currentHeight][currentWidth].rgbtRed = sepiaRed;
            image[currentHeight][currentWidth].rgbtGreen = sepiaGreen;
            image[currentHeight][currentWidth].rgbtBlue = sepiaBlue; 
        }
    }

    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int currentHeight = 0; currentHeight < height; currentHeight++)
    {
        for (int currentWidth = 0; currentWidth < width/2; currentWidth++)
        {
            RGBTRIPLE tempImage[height][width];
            tempImage[currentHeight][currentWidth] = image[currentHeight][currentWidth];
            image[currentHeight][currentWidth] = image[currentHeight][width - (currentWidth+1)];
            image[currentHeight][width - (currentWidth+1)] = tempImage[currentHeight][currentWidth];
        }
    }

    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int currentHeigth = 0; currentHeigth < height; currentHeigth++)
    {
        for (int currentWidth = 0; currentWidth < width; currentWidth++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            int counter = 0;

            if (currentHeigth >= 0 && currentWidth >= 0) //center pixel
            {
                red += image[currentHeigth][currentWidth].rgbtRed;
                green += image[currentHeigth][currentWidth].rgbtGreen;
                blue += image[currentHeigth][currentWidth].rgbtBlue;
                counter++;
            }

            if (currentWidth >= 1) //left center pixel
            {
                red += image[currentHeigth][currentWidth-1].rgbtRed;
                green += image[currentHeigth][currentWidth-1].rgbtGreen;
                blue += image[currentHeigth][currentWidth-1].rgbtBlue;
                counter++;
            }

            if (currentWidth >= 1 && currentHeigth <= (height-1)) //left bottom pixel
            {
                red += image[currentHeigth+1][currentWidth-1].rgbtRed;
                green += image[currentHeigth+1][currentWidth-1].rgbtGreen;
                blue += image[currentHeigth+1][currentWidth-1].rgbtBlue;
                counter++;
            }

            if (currentWidth >= 1 && currentHeigth >= 1) //left upper pixel
            {
                red += image[currentHeigth-1][currentWidth-1].rgbtRed;
                green += image[currentHeigth-1][currentWidth-1].rgbtGreen;
                blue += image[currentHeigth-1][currentWidth-1].rgbtBlue;
                counter++;
            }

            if (currentHeigth >= 1) //upper center pixel
            {
                red += image[currentHeigth-1][currentWidth].rgbtRed;
                green += image[currentHeigth-1][currentWidth].rgbtGreen;
                blue += image[currentHeigth-1][currentWidth].rgbtBlue;
                counter++;
            }

            if (currentHeigth >= 1 && currentWidth <= (width-1)) //upper right pixel
            {
                red += image[currentHeigth-1][currentWidth+1].rgbtRed;
                green += image[currentHeigth-1][currentWidth+1].rgbtGreen;
                blue += image[currentHeigth-1][currentWidth+1].rgbtBlue;
                counter++;
            }

            if (currentWidth <= (width-1)) //right center pixel
            {
                red += image[currentHeigth][currentWidth+1].rgbtRed;
                green += image[currentHeigth][currentWidth+1].rgbtGreen;
                blue += image[currentHeigth][currentWidth+1].rgbtBlue;
                counter++;
            }

            if(currentHeigth <= (height-1) && currentWidth <= (width-1)) //right bottom pixel
            {
                red += image[currentHeigth+1][currentWidth+1].rgbtRed;
                green += image[currentHeigth+1][currentWidth+1].rgbtGreen;
                blue += image[currentHeigth+1][currentWidth+1].rgbtBlue;
                counter++;
            }

            if(currentHeigth <= (height-1)) //bottom center pixel
            {
                red += image[currentHeigth+1][currentWidth].rgbtRed;
                green += image[currentHeigth][currentWidth].rgbtGreen;
                blue += image[currentHeigth+1][currentWidth].rgbtBlue;
                counter++;
            }

            image[currentHeigth][currentWidth].rgbtRed = round(red/counter);
            image[currentHeigth][currentWidth].rgbtGreen = round(green/counter);
            image[currentHeigth][currentWidth].rgbtBlue = round(blue/counter);
        }
    }

    return;
}
