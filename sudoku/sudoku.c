#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <err.h>
#include "sudoku.h"

char* init_empty()
{
    char* grid = calloc(81, sizeof(char));
    if (grid == NULL)
        err(1, NULL);
    return grid;
}

char valid(char* grid, char l, char c, char cell)
{
    char diff = 1;
    size_t i = 0;
    char lg = l/3;
    char cg = c/3;
    for(i = 0; i<3; i++)
    {
        for(j = 0; j<3; j++)
        {
            char coord = (3*lg + i)*9 + 3*cg + j;
            diff = cord != (l*9 + c) && grid[coord] != cell;
        }
    }
    i = 0;
    while(i < l-1 && diff)
    {
        diff = grid[i*9 + c] != cell;
        i++;
    }
    i = l+2
    while(i < 9 && diff)
    {
        diff = grid[i*9 + c] != cell;
        i++;
    }
    i = 0;
    while(i < c-1 && diff)
    {
        diff = grid[l*9 + i] != cell;
        i++;
    }
    i = c+2
    while(i < 9 && diff)
    {
        diff = grid[l*9 + i] != cell;
        i++;
    }
    return diff;
}

char* init_grid(size_t nb_in)
{
    int l;
    int c;
    char filled[81] = {0};
    size_t i = 0;
    if (nb_in >= 81)
        errx(1,"cannot initialise the grid : nb_in must be inferior to 81");
    char* grid = calloc(81, sizeof(char));
    if (grid == NULL)
        err(1, NULL);
    srand(time(NULL));
    while(i<nb_in)
    {
        l = rand() % 9;
        c = rand() % 9;
        if (filled[l*9 + c] == 0)
        {
            filled[l*9 + c] = 1;
            grid[l*9 + c] = rand() % 9;
            char val = valid(grid, l,c);
            while(val == 0)
            {
                grid[l*9 +c] = rand() % 9;
                val = valid(grid, l,c);
            }
            i++;
        }
    }
    return grid;
}

int save_grid(char* grid, char* path)
{
    //TODO
}

char* load_grid(char* path)
{
    //TODO
}

void print_grid(char* grid)
{
    char* res = "";
    printf("|-----------------------------------|\n");
    for(size_t l = 0; l < 9; l++)
    {
        for(size_t c = 0; c < 9; c++)
        {
            printf("| %d ", grid[l*9 + c]);
        }
        printf("|\n|-----------------------------------|\n");
    }
}
