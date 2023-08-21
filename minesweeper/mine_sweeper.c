#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point{
    int x;
    int y;
};


int main() 
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

    // Declare and initialize a 2D array
    int grid[rows][cols];

    int max;

    if (rows > cols)
    {
        max = rows;
    }
    else
    {
        max = cols;
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            grid[i][j] = 0;
        }
    }
    
    int x, y = max +2;
    int rand1, rand2 = max + 1;

    unsigned int seedValue = (unsigned int)time(NULL); // Get the current time as a seed
    srand(seedValue);

    for (int i = 0; i <= mines; i++){
        while (x == rand1 && y == rand2){
            rand1 = rand() % max;
            rand2 = rand() % max;
        }
        x = rand1;
        y = rand2;
        grid[x][y] = 1;
    }



    // Access and print the values in the 2D array
    printf("Grid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
