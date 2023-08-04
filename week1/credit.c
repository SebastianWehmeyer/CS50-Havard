#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) 
{
    int number;
    char string[50];
    char second_string[20];
    int second_digits;
    int sum_second_digits = 0;
    int add_second;
    int sum_first_digits = 0;
    int add_first;
    int c = 0;

    do {
    printf("Number: ");
    scanf("%s", string);
    number = atoi(string);
    } while(number == 0);

    int length = strlen(string);

    for (int h = (length-1); h >= 0; h-=2) {
        add_first = string[h] - '0';
        sum_first_digits = sum_first_digits + add_first; 
    } 

    for (int i = (length-2); i >= 0; i-=2){

        second_digits = string[i] - '0';
        second_digits = second_digits*2;

        if (second_digits >= 10) {

            second_digits = second_digits-10;
            second_string[c] = '1';
            second_string[c+1] = second_digits +'0';
            c++;

        } else {
          second_string[c] = second_digits + '0';     
        }
        c++;       
    }

    int second_length = strlen(second_string);

    for (int k = 0; k <= (second_length-1); k++) {
        add_second = second_string[k] - '0';
        sum_second_digits = sum_second_digits + add_second;
    }

    int zero = sum_first_digits + sum_second_digits;
    zero %= 10;

    if (zero == 0) {

        if ((string[0] == '3' && string[1] == '4' && length == 15) || (string[0] == '3' && string[1] == '7' && length == 15)) {

            printf("AMEX \n");

        } else if (string[0] == '4') {

            if(length == 13 || length == 16) {

                printf("VISA \n");

            } 

        } else if (length == 16 && string[0] == '5') {

            if (string[1] == '1' || string[1] == '2' || string[1] == '3' || string[1] == '4' || string[1] == '5') {

                printf("MASTERCARD \n");

            }
        } 
    } else {
        printf("INVALID \n");
    }
    
}
