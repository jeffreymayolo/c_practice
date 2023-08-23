#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generate_grid.h"


int main(void) 
{
    int rows, cols, mines;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the number of mines: ");
    scanf("%d", &mines);
    if (mines > rows*cols){
        printf("Error: Too many mines\n");
        return 1;
    }

    // initialize grid
    int **grid = generate_grid(rows, cols, mines);

    // Print contents of grid
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%i", grid[i][j]);
        }
        printf("\n");
    }

    // Free grid
    free_grid(grid, rows);
    return 0;
}
