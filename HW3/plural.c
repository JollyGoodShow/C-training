#include <stdio.h>
#include <string.h>

//Given a noun, attempts to pluralize that noun, following
//some basic grammar rules. Mario d'Andrea 2016


void pluralize (char*, char*); //declare function

int main(void) {
    //Get user input
    char userNoun[15] = "";
    char pluralNoun[17] = "";

    printf("Please enter a word: ");
    scanf("%s", userNoun);

    //Call a function that pluralizes the noun
    pluralize(userNoun, pluralNoun);

    printf("The plural of %s is %s\n", userNoun, pluralNoun);

    return 0;
}

void pluralize (char* userNoun, char* pluralNoun) {
    //Applies some basic grammer to pluralize the word
    char lastChar = ' ';
    char secondLastChar = ' ';
    int length = strlen(userNoun);
    const char VOWELS[] = "aeiou";

    lastChar = userNoun[length - 1];
    secondLastChar = userNoun[length - 2];

    strcpy(pluralNoun, userNoun);

    switch(lastChar) {
        case 'h':
           if ( (secondLastChar == 'c') || (secondLastChar == 's')) {
               //fall through to add an es
           } else {
               pluralNoun[length] = 's';
               break;
           }
        case 's':
        case 'x':
        case 'z':
           pluralNoun[length] = 'e';
           pluralNoun[length+1] = 's';
           break;
        case 'y':
           if (strchr(VOWELS, secondLastChar) == NULL) {
               pluralNoun[length-1] = 'i';
               pluralNoun[length] = 'e';
               pluralNoun[length+1] = 's';
               break;
           }
        case 'e':
           if (secondLastChar == 'f') {
               pluralNoun[length-2] = 'v';
               pluralNoun[length-1] = 'e';
               pluralNoun[length] = 's';
               break;
           } else {
               pluralNoun[length] = 's';
               break;
           }

        case 'f':
           pluralNoun[length - 1] = 'v';
           pluralNoun[length] = 'e';
           pluralNoun[length + 1] = 's';
           break;

        default:
           pluralNoun[length] = 's';
           break;
    }

    strcat(pluralNoun, ""); //add null character to the end

    return;
}
