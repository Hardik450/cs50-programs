// // A credit (or debit) card, of course, is a plastic card with which you can pay for goods and
// services.
// // Printed on that card is a number that’s also stored in a database somewhere, so that when your
// card is used to buy something, the creditor knows whom to bill. There are a lot of people with
// credit cards in this world, so those numbers are pretty long: American Express uses 15-digit
// numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers.
// // And those are decimal numbers (0 through 9), not binary, which means, for instance, that
// American Express could print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um,
// a quadrillion.)

// // Actually, that’s a bit of an exaggeration, because credit card numbers actually have some
// structure to them.
// // All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52,
// 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern
// ourselves with for this problem); and all Visa numbers start with 4.
// // But credit card numbers also have a “checksum” built into them, a mathematical relationship
// between at least one number and others.
// // That checksum enables computers (or humans who like math) to detect typos (e.g.,
// transpositions), if not fraudulent numbers, without having to query a database, which can be
// slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless
// respects the mathematical constraint, so a database lookup is still necessary for more rigorous
// checks.

// // In a file called credit.c in a folder called credit, implement a program in C that checks the
// validity of a given credit card number. #include <cs50.h> #include <stdio.h>

// int main(void){
//     long number = get_long("Number: ");
//     long numdigit[18];
//     int i = 0;
//     int sum = 0;
//     //this code stores the value in array and gives the length of an array
//     while(number > 0){
//         numdigit[i] = number % 10;
//         number /= 10;
//         i++;
//     }
//     for(int j = i-1; j >= 0; j--){

//         if(j % 2 == 0){
//             sum += numdigit[j];
//         }
//     }
//       for(int j = i-1; j >= 0; j--){

//         if(j % 2 != 0){
//             sum += numdigit[j]*2;
//         }
//     }
//     sum = sum - 9;
//     if(i == 13){
//         printf("VISA\n");
//     }
//     else if(i == 15 && sum == 20){
//         printf("AMEX\n");
//     }
//     else if(i==16){
//         printf("MASTERCARD\n");
//     }
//     else{
//         printf("INVALID\n");
//     }
// }
// //4003600000000014
#include <cs50.h>
#include <stdio.h>

// Functions Declaration
long get_credit_number(void);
long checksum(long credit_number);
void finalcheck(long check_sum, long credit_number);

// Driver code
int main(void)
{
    // Calling the Functions
    long credit_number = get_credit_number();
    long check_sum = checksum(credit_number);
    finalcheck(check_sum, credit_number);
}

// Prompt user to enter the credit card number
long get_credit_number(void)
{
    long credit_num;
    do
    {
        credit_num = get_long("Number: ");
    }
    while (credit_num <= 0);
    return credit_num;
}

// Checksum by Luhm algorithm
long checksum(long credit_number)
{
    long sum = 0;
    long last_digit;
    long credit_card_number = credit_number;
    // Luhm's algorithm Case 1
    while (credit_card_number > 0)
    {
        last_digit = credit_card_number % 10;
        sum = sum + last_digit;
        credit_card_number = credit_card_number / 100;
    }

    credit_card_number = credit_number / 10;
    long two_times;
    // Luhm's algorithm Case 2
    while (credit_card_number > 0)
    {
        last_digit = credit_card_number % 10;
        two_times = 2 * last_digit;
        sum = sum + (two_times % 10) + (two_times / 10);
        credit_card_number = credit_card_number / 100;
    }
    sum = sum % 10;
    // Check whether the last digit of sum is 0 or not
    if (sum == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Final check whether the card is Visa, Amex, Mastercard or Invalid
void finalcheck(long check_sum, long credit_number)
{
    long valid_cc = credit_number;
    int length = 0;
    long divisor = 10;
    int first_digit;
    int first_twodigit;

    if (check_sum == 1)
    {
        // Check length of credit card number
        while (valid_cc > 0)
        {
            valid_cc = valid_cc / 10;
            length++;
        }

        // Check first two digits of credit card number
        valid_cc = credit_number;
        for (int i = 0; i < (length - 2); i++)
        {
            divisor = divisor * 10;
        }

        first_digit = valid_cc / divisor;
        first_twodigit = valid_cc / (divisor / 10);

        // check whether card is AMEX
        if (length == 15 && (first_twodigit == 34 || first_twodigit == 37))
        {
            printf("AMEX\n");
        }
        // check whether card is MASTERCARD
        else if (length == 16 && (first_twodigit >= 50 && first_twodigit <= 55))
        {
            printf("MASTERCARD\n");
        }
        // check whether card id VISA
        else if ((length == 13 || length == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
