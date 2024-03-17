#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGHT 1000
#define MAX_VALUES 100

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *file = fopen("inputs/input_day2", "r");

    if (!file) {
        printf("Error: File not found\n");
        return 1;
    }

    char line[MAX_LINE_LENGHT];
    int checksum1 = 0;
    int checksum2 = 0;
    char *token;

    while (fgets(line, MAX_LINE_LENGHT, file)) {
        char *s = line;
        int i = 0;
        int values[MAX_VALUES];

        token = strtok(s, " \t");
        while (token  != NULL) {
            values[i++] = atoi(token);

            token = strtok(NULL, " \t");
        }

        qsort(values, i, sizeof(int), compare);

        for (int j = 0; j < i; j++) {
            for (int k = j + 1; k < i; k++) {
                if (values[k] % values[j] == 0) {
                    checksum2 += values[k] / values[j];
                    break;
                }
            }
        }

        checksum1 += values[i - 1] - values[0];
    }

    printf("Checksum Part 1: %d\n", checksum1);
    printf("Checksum Part 2: %d\n", checksum2);
    fclose(file);
    
    return 0;
}