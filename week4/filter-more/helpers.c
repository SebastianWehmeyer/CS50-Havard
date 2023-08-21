#include "helpers.h"
#include <math.h>
#include <stdio.h>

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

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];

    for (int currentHeigth = 0; currentHeigth < height; currentHeigth++)
    {
        for (int currentWidth = 0; currentWidth < width; currentWidth++)
        {
            int gxRed, gxGreen, gxBlue;
            int gyRed, gyGreen, gyBlue;
            int edgesRed, edgesGreen, edgesBlue;

            gxRed = ((image[currentHeigth-1][currentWidth-1].rgbtRed * (-1)) + (image[currentHeigth][currentWidth-1].rgbtRed * (-2)) + (image[currentHeigth+1][currentWidth-1].rgbtRed * (-1)) + (image[currentHeigth-1][currentWidth+1].rgbtRed) + (image[currentHeigth][currentWidth+1].rgbtRed * 2) + (image[currentHeigth+1][currentWidth+1].rgbtRed));
            gyRed = ((image[currentHeigth-1][currentWidth-1].rgbtRed * (-1)) + (image[currentHeigth-1][currentWidth].rgbtRed * (-2)) + (image[currentHeigth-1][currentWidth+1].rgbtRed * (-1)) + (image[currentHeigth+1][currentWidth-1].rgbtRed) + (image[currentHeigth+1][currentWidth].rgbtRed * 2) + (image[currentHeigth+1][currentWidth+1].rgbtRed));
            edgesRed = round(sqrt((gxRed * gxRed) + (gyRed * gyRed)));

            if (edgesRed > 255) edgesRed = 255;

            gxGreen = ((image[currentHeigth-1][currentWidth-1].rgbtGreen * (-1)) + (image[currentHeigth][currentWidth-1].rgbtGreen * (-2)) + (image[currentHeigth+1][currentWidth-1].rgbtGreen * (-1)) + (image[currentHeigth-1][currentWidth+1].rgbtGreen) + (image[currentHeigth][currentWidth+1].rgbtGreen * 2) + (image[currentHeigth+1][currentWidth+1].rgbtGreen));
            gyGreen = ((image[currentHeigth-1][currentWidth-1].rgbtGreen * (-1)) + (image[currentHeigth-1][currentWidth].rgbtGreen * (-2)) + (image[currentHeigth-1][currentWidth+1].rgbtGreen * (-1)) + (image[currentHeigth+1][currentWidth-1].rgbtGreen) + (image[currentHeigth+1][currentWidth].rgbtGreen * 2) + (image[currentHeigth+1][currentWidth+1].rgbtGreen));  
            edgesGreen = round(sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen)));

            if (edgesGreen > 255) edgesGreen = 255;

            gxBlue = ((image[currentHeigth-1][currentWidth-1].rgbtBlue * (-1)) + (image[currentHeigth][currentWidth-1].rgbtBlue * (-2)) + (image[currentHeigth+1][currentWidth-1].rgbtBlue * (-1)) + (image[currentHeigth-1][currentWidth+1].rgbtBlue) + (image[currentHeigth][currentWidth+1].rgbtBlue * 2) + (image[currentHeigth+1][currentWidth+1].rgbtBlue));
            gyBlue = ((image[currentHeigth-1][currentWidth-1].rgbtBlue * (-1)) + (image[currentHeigth-1][currentWidth].rgbtBlue * (-2)) + (image[currentHeigth-1][currentWidth+1].rgbtBlue * (-1)) + (image[currentHeigth+1][currentWidth-1].rgbtBlue) + (image[currentHeigth+1][currentWidth].rgbtBlue * 2) + (image[currentHeigth+1][currentWidth+1].rgbtBlue));
            edgesBlue = round(sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue)));

            if (edgesBlue > 255) edgesBlue = 255;

            tempImage[currentHeigth][currentWidth].rgbtRed = edgesRed;
            tempImage[currentHeigth][currentWidth].rgbtGreen = edgesGreen;
            tempImage[currentHeigth][currentWidth].rgbtBlue = edgesBlue;
        }
    }

    for (int currentHeigth = 0; currentHeigth < height; currentHeigth++)
    {
        for (int currentWidth = 0; currentWidth < width; currentWidth++)
        {
            image[currentHeigth][currentWidth].rgbtRed = tempImage[currentHeigth][currentWidth].rgbtRed;
            image[currentHeigth][currentWidth].rgbtGreen = tempImage[currentHeigth][currentWidth].rgbtGreen;
            image[currentHeigth][currentWidth].rgbtBlue = tempImage[currentHeigth][currentWidth].rgbtBlue;
        }
    }

    return;
}
