#include "cs50.h"
#include <stdio.h>
#include <string.h>

// cc bulbs.c -o bulbs cs50.c

const int BITS_IN_BYTE = 8;
void print_bulb(int bit);

int main(void)
{
    string input_text = get_string("Message: ");
    char * input_text_as_char = input_text;
    int decimal_for_binary;

    for (int n = 0; n < strlen(input_text); n++)
    {
        char binary_code[] = {0, 0 ,0 ,0 ,0 ,0 ,0 ,0};
        decimal_for_binary = input_text[n];

        for (int j = 0; j < 8; j++)
        {
            if (decimal_for_binary >= 128)
            {
                binary_code[0] = 1;
                decimal_for_binary -= 128;
            } 
            else if (decimal_for_binary < 128 && decimal_for_binary >= 64)
            {
                binary_code[1] = 1;
                decimal_for_binary -= 64;
            } 
            else if (decimal_for_binary < 64 && decimal_for_binary >= 32)
            {
                binary_code[2] = 1;
                decimal_for_binary -= 32;
            } 
            else if (decimal_for_binary < 32 && decimal_for_binary >= 16)
            {
                binary_code[3] = 1;
                decimal_for_binary -= 16;
            } 
            else if (decimal_for_binary < 16 && decimal_for_binary >= 8)
            {
                binary_code[4] = 1;
                decimal_for_binary -= 8;
            } 
            else if (decimal_for_binary < 8 && decimal_for_binary >= 4)
            {
                binary_code[5] = 1;
                decimal_for_binary -= 4;
            } 
            else if (decimal_for_binary < 4 && decimal_for_binary >= 2)
            {
                binary_code[6] = 1;
                decimal_for_binary -= 2;
            } 
            else if (decimal_for_binary == 1)
            {
                binary_code[7] = 1;
                decimal_for_binary -= 1;
            }
        }

        for (int binary_element = 0; binary_element < 8; binary_element++)
        {
            print_bulb(binary_code[binary_element]);
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
