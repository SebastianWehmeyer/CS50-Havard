#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {

    int count = 0;
    char cents[100];
    int change;

    do {
    printf("Change owed: ");
    fgets(cents, 100, stdin);
    change = atoi(cents);
    printf("%d", change);
    } while (change <= 0);


    do {

        if (change == 0){

            change -= 1;

        } else if (change >= 25) {

            count +=1;
            change -= 25;

        } else if (change < 25 && change >= 10) {

            count += 1;
            change -= 10;

        } else if (change < 10 && change >= 5) {

            count += 1;
            change -= 5;

        } else if (change > 0 && change <= 4){

            count += 1;
            change -= 1;

        }

    } while (change >= 0);
    printf("%d\n", count);
}
