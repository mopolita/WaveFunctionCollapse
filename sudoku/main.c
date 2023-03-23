#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <err.h>
#include "sudoku.h"

// Generates the possibilities lists of each cell
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

//Removes an element "val" from a list of chars
void del(char** list, char val, size_t len)
{
    size_t pos = 0;
    while(pos < 9 && *list[pos] != val)
    {
        pos++;
    }
    if(pos >= 9)
    {
        errx(1, "An error occured during update of possibilities lists");
    }
    for(size_t i = pos-1; i < len - 1; i++)
    {
        list[i] = list[i + 1];
    }
    *list = realloc(*list, (len - 1)*sizeof(char));
    
}

//Update the lists of possibilities (unfinished)
void update_lists(char* grid, char** lists, char l, char c, char nb)
{
    size_t i = 0;
    char lg = l/3;
    char cg = c/3;
    for(i = 0; i<3; i++)
    {
        for(size_t j = 0; j<3; j++)
        {
            continue;
        }
    }
    i = 0;
    while(i < lg*3 - 1 && diff)
    {
        i++;
    }
    i = lg*3 + 2;
    while(i < 9 && diff)
    {
        i++;
    }
    i = 0;
    while(i < cg*3 - 1 && diff)
    {
        i++;
    }
    i = cg*3 + 2;
    while(i < 9 && diff)
    {
        i++;
    }
}

//Gets a position for one of the cells with the minimal possibilities
char random_min_pos(char** lists)
{
    //TODO
}

//The solver of the Sudoku, using an implementation of the Wave Collapse function
char* collapse_solver(char* grid, char alr_filled)
{
    char** lists = generate_lists(grid);
    char* nb;
    char to_fill = 81 - alr_filled;
    char min;
    while(to_fill > 0)
    {
        min = random_min_pos(lists);
        nb = lists[min];
        grid[min] = nb;
        update_lists(grid, lists, min / 9, min % 9, nb);
        to_fill--;
    }
    return grid;
}

int main(int argc, char* argv[])
{
    //TODO
}
