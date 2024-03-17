#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

char *read(char *filename) {
    FILE *file_ptr;
    char *data;
    size_t buffer_size = 1000; // Initial buffer size
    size_t total_bytes = 0;
    size_t bytes_read;

    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("Error, file open failed!");
        return NULL;
    }

    data = malloc(buffer_size * sizeof(char));
    if (data == NULL) {
        printf("Error, memory allocation failed!");
        fclose(file_ptr);
        return NULL;
    }

    while ((bytes_read = fread(data + total_bytes, sizeof(char), buffer_size - total_bytes, file_ptr)) > 0) {
        total_bytes += bytes_read;
        if (total_bytes >= buffer_size) {
            // Expand the buffer size
            buffer_size *= 2;
            data = realloc(data, buffer_size * sizeof(char));
            if (data == NULL) {
                printf("Error, memory reallocation failed!");
                fclose(file_ptr);
                return NULL;
            }
        }
    }

    fclose(file_ptr);

    data[total_bytes] = '\0';

    return data;
}
