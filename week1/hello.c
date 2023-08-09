#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    printf("What's your name? ");
    fgets(name, 100, stdin);
    printf("Hello, %s", name);
}
