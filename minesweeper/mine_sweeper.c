#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generate_grid.h"


int main(void) 
{
    int grid = generate_grid();
    if (1 == grid)
    {
        printf("Error generating grid\n");
        return 1;
    }

    return 0;
}
