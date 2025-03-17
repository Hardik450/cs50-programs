#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

int count_letters(string a);
int count_words(string a);
int count_sentences(string a);
void grade(int a);
int main(void){
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float L = letters/words * 100;
    float S = sentences/words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    grade(index);
    // printf("%i\n",index);
}
int count_letters(string a){
    int i = 0;
    int count = 0;
    while(a[i] != '\0'){
        if(isalpha(a[i])){
           count++;
        }
        i++;
    }
    return count;
}
int count_words(string a){
    int i = 0;
    int count = 0;
    while(a[i] != '\0'){
           if(a[i] == ' '){
            count++;
           }
        i++;
        }
    return count + 1;
    }

int count_sentences(string a){
    int i = 0;
    int count = 0;
    while(a[i] != '\0'){
           if(a[i] == '.' || a[i] == '?' || a[i] == '!'){
            count++;
           }

        i++;
        }
    return count;
    }

void grade(int a){
    if(a < 1){
        printf("Before Grade 1\n");
    }
    else if(a >= 1 && a < 16){
        printf("Grade %i\n", a);
    }
    else{
        printf("Grade 16+\n");
    }
}
