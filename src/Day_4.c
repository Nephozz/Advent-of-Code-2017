#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE_PATH "inputs/input_day4"
#define MAX_PASSPHRASE_LENGTH 100
#define MAX_WORD_LENGTH 20
#define true 1
#define false 0
#define bool int


void trimNewline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

bool isAnagram(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2) {
        return false;
    }

    int charCount1[26] = {0};
    int charCount2[26] = {0};

    for (int i = 0; i < len1; i++) {
        charCount1[word1[i] - 'a']++;
        charCount2[word2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (charCount1[i] != charCount2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    FILE *file = fopen(INPUT_FILE_PATH, "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    int validPassphrases = 0;
    char line[MAX_PASSPHRASE_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, " ");
        char *words[MAX_WORD_LENGTH];
        int wordCount = 0;

        while (word != NULL) {
            trimNewline(word);
            words[wordCount++] = word;
            word = strtok(NULL, " ");
        }

        int isValid = true;

        for (int i = 0; i < wordCount; i++) {
            for (int j = i + 1; j < wordCount; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    isValid = false;
                    break;
                } else if (isAnagram(words[i], words[j])) {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid) {
            validPassphrases++;
        }
    }

    fclose(file);

    printf("Valid passphrases Part2: %d\n", validPassphrases);
    return 0;
}