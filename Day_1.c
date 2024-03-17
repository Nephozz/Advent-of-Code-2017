#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr;
    char *data;
    size_t bytes_read;
    int sum = 0;

    file_ptr = fopen("inputs/input_day1", "r");

    if (file_ptr == NULL) {
        printf("Error, file open failed!");
        return 1;
    }

    data = malloc(1000 * sizeof(char));

    if (data == NULL) {
        printf("Error, memory allocation failed!");
        return 1;
    }

    bytes_read = fread(data, sizeof(char), 1000, file_ptr);

    if (bytes_read == 0) {
        printf("Error, file read failed!");
        return 1;
    }

    for (int i = 0; i < bytes_read; i++) {
        if (data[i] == data[(i + 1) % bytes_read]) {
            sum += data[i] - '0';
        }
    }

    printf("Sum: %d\n", sum);

    fclose(file_ptr);
    free(data);

    return 0;
}
