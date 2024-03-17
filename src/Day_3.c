#include <stdio.h>
#include <stdlib.h>

#define INPUT 325489

void part1();
void part2();

int main() {
    
    part1();
    part2();

    return 0;
}

void part1() {
    int size = 1;

    while (size * size < INPUT) {
        size += 2;
    }

    // Calculate the steps to the center of the spiral
    int steps = size * size - INPUT;
    
    printf("Steps: %d\n", steps);
}

int sumNeighbors(int **grid, int x, int y) {
    int sum = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            sum += grid[i][j];
        }
    }

    return sum;
}

void part2() {
    int size = 11;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    int x = size / 2;
    int y = size / 2;
    int dx = 1;
    int dy = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }

    grid[x][y] = 1;

    while (grid[x][y] < INPUT) {
        x += dx;
        y += dy;

        if (grid[x][y] == 0) {
            if (dx == 1 && dy == 0) {
                if (grid[x][y + 1] == 0) {
                    dy = 1;
                    dx = 0;
                }
            } else if (dx == 0 && dy == 1) {
                if (grid[x - 1][y] == 0) {
                    dy = 0;
                    dx = -1;
                }
            } else if (dx == -1 && dy == 0) {
                if (grid[x][y - 1] == 0) {
                    dy = -1;
                    dx = 0;
                }
            } else if (dx == 0 && dy == -1) {
                if (grid[x + 1][y] == 0) {
                    dy = 0;
                    dx = 1;
                }
            }
        }

        grid[x][y] = sumNeighbors(grid, x, y);
    }

    printf("Value: %d\n", grid[x][y]);
}