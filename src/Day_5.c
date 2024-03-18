#include <stdio.h>
#include <stdlib.h>

#define NB_INSTRUCTIONS 1003
#define LINE_LENGTH 10

int main() {
    FILE *file = fopen("inputs/day5", "r");

    if (!file) {
        printf("Error: File not found\n");
        return 1;
    }

    int instructions[NB_INSTRUCTIONS];
    char line[LINE_LENGTH];
    int i = 0;

    while (fgets(line, 10, file)) {
        instructions[i++] = atoi(line);
    }

    fclose(file);

    int steps = 0;

    for (int i = 0; i < NB_INSTRUCTIONS; steps++) {
        int jump = instructions[i];
        instructions[i] += jump >= 3 ? -1 : 1;
        i += jump;
    }

    printf("Number of steps: %d\n", steps);

    return 0;
}