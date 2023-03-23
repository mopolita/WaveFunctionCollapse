#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <err.h>
#include "sudoku.h"

char** generate_lists(char* grid)
{
    for(size_t l = 0; i < 9; i++)
    {
        for(size_t c = 0; i < 9; i++)
        {
            if(grid[l*9 +c] == 0)
            {
                //TODO
            }
        }
    }
}

char** update_lists(char* grid, char** lists, char l, char c, char nb)
{
    //TODO
}

char random_min_pos(char** lists)
{
    //TODO
}

char* collapse_solver(char* grid)
{
    //TODO
}

int main(int argc, char* argv[])
{
    //TODO
}
