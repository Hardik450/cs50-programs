#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void){
    // long number[20];
    // for(int i = 0; i <= 9-1; i++){
    //     number[i] = pow(2,i);
    // printf("%ld\n", number[i]);
    // }
    string phrase = get_string("Enter a phrase: ");
    for(int i = 0; i < strlen(phrase); i++){
        printf("%i ", phrase[i]);
    }
    printf("\n");
}

