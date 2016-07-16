#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Determines whether two words are anagrams of each other
//Mario D'Andrea, 2016
int are_anagrams(char [], char []);

int main(void) {
    //if two words are anagrams of each other, it means that they have
    //the same number of each letter as each other. I can tally up how many times
    //each letter appears in each word, and compare the tallies.
    char firstWord[20];
    char secondWord[20];

    printf("Please enter the first word: ");
    scanf("%s", firstWord);
    printf("Please enter the second word: ");
    scanf("%s", secondWord);

    if (are_anagrams(firstWord, secondWord) == 1) {
        printf("%s is an anagram of %s", firstWord, secondWord);
    } else {
        printf("%s is NOT an anagram of %s", firstWord, secondWord);
    }

    return 0;
}

int are_anagrams(char firstWord[], char secondWord[]) {
    int alphabetTallyOne[26];
    int alphabetTallyTwo[26];
    int i = 0;

    for (i=0; i<26; i++) {
        alphabetTallyOne[i] = 0;
        alphabetTallyTwo[i] = 0;
    }

    for (i=0; firstWord[i] != '\0'; i++) {
        firstWord[i] = tolower(firstWord[i]);
        alphabetTallyOne[firstWord[i] - 'a'] += 1;
    }

    for (i=0; secondWord[i] != '\0'; i++) {
        secondWord[i] = tolower(secondWord[i]);
        alphabetTallyTwo[secondWord[i] - 'a'] += 1;
    }

    for (i=0; i<26; i++) {
        if (alphabetTallyOne[i] != alphabetTallyTwo[i]) {
            return 0;
        }
    }
    return 1;
}