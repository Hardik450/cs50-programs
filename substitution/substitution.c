#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ciphertext(string text, string key);
bool uniquecharacter(string key);
bool is_valid_number(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}
int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) <= 0 || key == NULL)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }

    if (!is_valid_number(argv[1]))
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }
    if(!uniquecharacter(key)){
        printf("Key must contain 26 letters.\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    ciphertext(plaintext, key);
    return 0;
}
void ciphertext(string text, string key)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        int cipher = 0;
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            cipher += tolower(key[text[i]-'a']);
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            cipher += toupper(key[text[i]-'A']);
        }

        else
        {
            cipher += text[i];
        }
        printf("%c", cipher);
    }
    printf("\n");
}
//NQXPOMAFTRHLZGECYJIUWSKDVB
bool uniquecharacter(string key){
    for(int i = 0; i < strlen(key); i++){
        for(int j = 0; j < i; j++){
            if(key[i] == key[j]){
                return false;
            }
        }
    }
           return true;
}
