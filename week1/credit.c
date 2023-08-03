#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) 
{
    int number;
    char string[50];
    int second_digits;
    int sum_second_digits = 0;
    int add;
    char first_digits[10];

    do {

    printf("Number: ");
    scanf("%s", string);
    number = atoi(string);

    } while(number == 0);

    int length = strlen(string);

/*
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

    } else {

        printf("INVALID \n");

    }
    */

    for (int i = (length-2); i >= 0; i-=2){

        second_digits = string[i] - '0';
        second_digits = second_digits*2;
        char b[] = {second_digits}; 
        
    }
    printf("%d", second_digits);
    //char b[100] = second_digits + '0';

    /*for (int j = 0; j <= strlen(b); j++){

        add = b[j] - '0';
        sum_second_digits = sum_second_digits + add;

    }
    printf("%d", sum_second_digits);
    */
}