#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /*
    char word[100];
    printf("Enter a string: \n");
    fgets(word, sizeof(word), stdin);

    // Remove the extra storage allocated
    word[strcspn(word, "\n")] = '\0';

    printf("Word: %s\n", word);
    printf("Address: %p\n", &word);
    */

    // define desired number of rows and columns
    int rows = 3, cols = 4;

    // Allocate memory for an array of pointers. 
    int **matrix = (int **)malloc(rows * sizeof(int *));

    // For each pointer in the array, allocate memory for an array of ints
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    int position = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = position;
            position += 1;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j< cols; j++)
        {
            printf("%i", matrix[i][j]);
        }
        printf("\n");
    }

    // Free each array of ints
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    // Free the array of pointers
    free(matrix);

    return 0;
}