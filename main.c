#include <stdio.h>
#include <ctype.h>
#include <string.h>

void analyzeCharacter(char c);
void analyzeString(const char *str);
void menu();

int main() {
    char input[100];
    char choice;

    do {
        printf("Enter a single character or a string: ");
        scanf("%s", input);

        if (strlen(input) == 1) {
            analyzeCharacter(input[0]);
        } else {
            analyzeString(input);
        }
        
        printf("\nDo you want to analyze another input? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Exiting program.\n");
    return 0;
}

void analyzeCharacter(char c) {
    if (isdigit(c)) {
        if (c == '0' || c == '2' || c == '4' || c == '6' || c == '8') {
            printf("%c is an even number.\n", c);
        } else {
            printf("%c is an odd number.\n", c);
        }
    } else if (isalpha(c)) {
        char lowerC = tolower(c);
        if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
            printf("%c is a vowel.\n", c);
        } else {
            printf("%c is a consonant.\n", c);
        }
    } else {
        printf("%c is a special character or symbol.\n", c);
    }
}

void analyzeString(const char *str) {
    int vowels = 0, consonants = 0, digits = 0, specialChars = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            digits++;
        } else if (isalpha(str[i])) {
            char lowerC = tolower(str[i]);
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else {
            specialChars++;
        }
    }

    printf("String analysis:\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", specialChars);
}
