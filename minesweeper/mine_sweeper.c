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

    // initialize master grid
    char *type_1 = "master";
    int **master_grid = generate_grid(rows, cols, mines, type_1);

    // initialize display grid
    char *type_2 = "display";
    int **display_grid = generate_grid(rows, cols, mines, type_2);
    

    // print grid
    print_grid(master_grid, rows, cols);
    printf("\n");
    print_grid(display_grid, rows, cols);

    // Free grid
    free_grid(master_grid, rows);
    free_grid(display_grid, rows);
    return 0;
}

