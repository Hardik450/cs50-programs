// Suppose you work at a store and a customer gives you $1.00 (100 cents) for candy that costs $0.50 (50 cents).
// You’ll need to pay them their “change,” the amount leftover after paying for the cost of the candy.
// When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out (or annoy the customer!).
// In a file called cash.c in a folder called cash, implement a program in C that prints the minimum coins needed to make the given amount of change, in cents.
// But prompt the user for an int greater than 0, so that the program works for any amount of change:
// Re-prompt the user, again and again as needed, if their input is not greater than or equal to 0 (or if their input isn’t an int at all!).
#include <cs50.h>
#include <stdio.h>

int main(void){
    int change, count;
    count = 0;
    do{
        change = get_int("Change owed: ");
    }while(change < 0);
    while(change >= 25){
        change -= 25;
        count++;
    }
    while(change >= 10){
        change -= 10;
        count++;
    }
    while(change >= 5){
        change -= 5;
        count++;
    }
    while(change >= 1){
        change -= 1;
        count++;
    }
    printf("%i\n", count);
}
