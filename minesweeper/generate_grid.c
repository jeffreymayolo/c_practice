#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **generate_grid(int rows, int cols, int mines, char *type) 
{
    // Allocate memory for the grid
    int **grid = (int **)malloc(rows * sizeof(int *));

    // For each pointer in the array, allocate memory for an array of ints
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid to have all zeros
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            grid[i][j] = 0;
        }
    }

    // Stop function and return grid if it is a display grid
    if (strcmp(type, "display")==0)
    {
        return grid;
    }


    // Max grid coord of bomb is max of rows and columns 
    int max = (rows > cols) ? rows : cols;

    // Initialize random values to invalid values
    int x_coor_bomb;
    int y_coor_bomb;

    // Get current time and set it as the seed for random
    unsigned int seedValue = (unsigned int)time(NULL);
    srand(seedValue);

    // Loop through ang generate bombs for the number of mines
    for (int i = 1; i <= mines; i++)
    {
        do 
        {
            x_coor_bomb = rand() % max;
            y_coor_bomb = rand() % max;
        } while (grid[x_coor_bomb][y_coor_bomb]==1);

        grid[x_coor_bomb][y_coor_bomb] = 1;

    }

    return grid;
}

void free_grid(int **grid, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);
}

void print_grid(int **grid, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j<cols; j++)
        {
            printf("%i", grid[i][j]);
        }
        printf("\n");
    }
}