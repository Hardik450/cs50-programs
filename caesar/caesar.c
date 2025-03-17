#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ciphertext(string text, int key);
bool is_valid_number(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key <= 0 || key == ' ')
    {
        printf("Please Enter a Positive Integer as a key\n");
        return 1;
    }

    else if (!is_valid_number(argv[1]))
    {
        printf("Please Enter a Positive Integer as a key\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    ciphertext(plaintext, key);
    return 0;
}
void ciphertext(string text, int key)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        int cipher = 0;
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            cipher += (text[i] - 'a' + key) % 26 + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            cipher += (text[i] - 'A' + key) % 26 + 'A';
        }

        else
        {
            cipher += text[i];
        }
        printf("%c", cipher);
    }
    printf("\n");
}
