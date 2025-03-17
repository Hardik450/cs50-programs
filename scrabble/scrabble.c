#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

long scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
void uppercase(string a,string b);
long calculate(string c);
void compare(long d, long e);
int main(void){
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    uppercase(player1, player2);
    long score1 = calculate(player1);
    long score2 = calculate(player2);
    // printf("%ld\n", score1);
    // printf("%ld\n", score2);
    compare(score1,score2);
    printf("\n");
}

void uppercase(string a, string b){
    int i = 0;
    while(a[i] != '\0'){
        a[i] = toupper(a[i]);
        i++;
    }
    i = 0;
    while(b[i] != '\0'){
        b[i] = toupper(b[i]);
        i++;
    }
}
long calculate(string c){
    long numscore = 0;
    for(int i = 0; i < strlen(c); i++){
        if(isalpha(c[i])){
        numscore += scores[c[i] - 'A'];
        }
    }
    return numscore;
}
void compare(long d, long e){
    if(d > e){
        printf("Player 1 wins!");
    }
    else if(d < e){
        printf("Player 2 wins!");
    }
    else{
        printf("Tie!");
    }
}
