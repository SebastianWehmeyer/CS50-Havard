#include <stdio.h>

int main(void) {

    int count = 0;
    int change;

    do {

    printf("Change owed: ");
    scanf("%d", &change);

    } while (change < 0);

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
