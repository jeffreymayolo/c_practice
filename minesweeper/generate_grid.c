#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **generate_grid(rows, cols, mines) 
{
    // Allocate memory for the grid
    int **grid = (int **)malloc(rows * sizeof(int *));

    // For each pointer in the array, allocate memory for an array of ints
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Max grid coord of bomb is max of rows and columns 
    int max = (rows > cols) ? rows : cols;

    // Initialize the grid to have all zeros
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            grid[i][j] = 0;
        }
    }
    
    // initialize x_bomb, y_bomb to invalid values to be changes later
    int x_bomb, y_bomb = max +2;

    // Initialize random values to invalid values
    int rand1, rand2 = max + 1;

    // Get current time and set it as the seed for random
    unsigned int seedValue = (unsigned int)time(NULL);
    srand(seedValue);

    // Loop through ang generate bombs for the number of mines
    for (int i = 0; i <= mines; i++)
    {
        while (x_bomb == rand1 && y_bomb == rand2)
        {
            rand1 = rand() % max;
            rand2 = rand() % max;
        }
        x_bomb = rand1;
        y_bomb = rand2;
        grid[x_bomb][y_bomb] = 1;
    }
    return grid;
}

void free_grid(double **grid, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
}