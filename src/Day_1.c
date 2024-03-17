#include <stdio.h>
#include <stdlib.h>

void part1(char *data, size_t total_bytes);
void part2(char *data, size_t total_bytes);

int main() {
    FILE *file_ptr;
    char *data;
    size_t bytes_read;
    size_t total_bytes = 0;
    size_t buffer_size = 1000;

    file_ptr = fopen("inputs/input_day1", "r");

    if (file_ptr == NULL) {
        printf("Error, file open failed!");
        return 1;
    }

    data = malloc(buffer_size * sizeof(char));

    if (data == NULL) {
        printf("Error, memory allocation failed!");
        return 1;
    }

    while ((bytes_read = fread(data + total_bytes, sizeof(char), buffer_size, file_ptr)) > 0) {
        total_bytes += bytes_read;
        data = realloc(data, total_bytes + buffer_size);
    }

    fclose(file_ptr);

    part1(data, total_bytes);
    part2(data, total_bytes);

    free(data);

    return 0;
}

void part1(char *data, size_t total_bytes) {
    int sum = 0;

    for (size_t i = 0; i < total_bytes; i++) {
        if (data[i] == data[(i + 1) % total_bytes]) {
            sum += data[i] - '0';
        }
    }

    printf("Part 1 result:\n%d\n", sum);
}

void part2(char *data, size_t total_bytes) {
    int sum = 0;
    size_t half = total_bytes / 2;

    for (size_t i = 0; i < total_bytes; i++) {
        if (data[i] == data[(i + half) % total_bytes]) {
            sum += data[i] - '0';
        }
    }

    printf("Part 2 result:\n%d\n", sum);
}