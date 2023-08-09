#include "cs50.h"
#include <stdio.h>
#include <string.h>

// cc bulbs.c -o bulbs cs50.c

const int BITS_IN_BYTE = 8;
void print_bulb(int bit);

int main(void)
{
    string text_s = get_string("Message: ");
    char * text = text_s;
    int decimal;

    for (int n = 0; n < strlen(text); n++)
    {
        char array[] = {0, 0 ,0 ,0 ,0 ,0 ,0 ,0};
        decimal = text[n];

        for (int j = 0; j < 8; j++)
        {
            if (decimal >= 128)
            {
                array[0] = 1;
                decimal -= 128;
            } 
            else if (decimal < 128 && decimal >= 64)
            {
                array[1] = 1;
                decimal -= 64;
            } 
            else if (decimal < 64 && decimal >= 32)
            {
                array[2] = 1;
                decimal -= 32;
            } 
            else if (decimal < 32 && decimal >= 16)
            {
                array[3] = 1;
                decimal -= 16;
            } 
            else if (decimal < 16 && decimal >= 8)
            {
                array[4] = 1;
                decimal -= 8;
            } 
            else if (decimal < 8 && decimal >= 4)
            {
                array[5] = 1;
                decimal -= 4;
            } 
            else if (decimal < 4 && decimal >= 2)
            {
                array[6] = 1;
                decimal -= 2;
            } 
            else if (decimal == 1)
            {
                array[7] = 1;
                decimal -= 1;
            }
        }

        for (int i = 0; i < 8; i++)
        {
            print_bulb(array[i]);
        }

        printf("\n");
    }
}   

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
        