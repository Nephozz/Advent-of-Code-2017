#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

void part1(char *data, size_t total_bytes);
void part2(char *data, size_t total_bytes);

int main() {
    char *data  = read("inputs/input_day1");

    if (data == NULL) {
        return 1;
    }

    printf("Data:\n%s\n", data);

    return 0;
}

