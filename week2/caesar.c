#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// cc caesar.c -o caesar cs50.c
char caesar(char[], int);

int main(int argc, string argv[]) 
{
   
    if (argc == 2){
        int key = atoi(argv[1]);
        if (argc == 2 && key > 0) {
            char new_code[100];
            string text = get_string("plaintext: ");
            char * code = text;
            printf("ciphertext: ");
            new_code = caesar(code, key);
            printf("%s", new_code);
          /*  for (int n = 0; n < strlen(code); n++){  
                printf("%c", caesar(code[n], key));
            } */

        } else {
            printf("./caesar key \n");
            return 1;
        }

    } else {
         printf("./caesar key \n");
            return 1;
    }
    
}

char caesar (char code_f[], int key_f) {
    char new[10000];
    for (int i = 0; i < strlen(code_f); i++) {
        int rotate = code_f[i];
        if (code_f[i] == ' ') {
            new[i] = ' ';
            i++;
        } 
        for (int j = 0; j < key_f; j++){
            if (rotate == 90 || rotate == 122) {
                rotate -= 26;  
            }
            rotate++;
        }
        new[i] = rotate;
    }
    return * new;
}