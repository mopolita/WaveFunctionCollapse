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

size_t len(char* list)
{
    //TODO
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
        warnx("No deletion occured");
        return;
    } 
    for(size_t i = pos-1; i < len - 1; i++)
    {
        list[i] = list[i + 1];
    }
    *list = realloc(*list, (len - 1)*sizeof(char));
    
}

//Update the lists of possibilities
void update_lists(char* grid, char** lists, char l, char c, char nb)
{
    size_t i = 0;
    char lg = l/3;
    char cg = c/3;
    char** curr;
    for(i = 0; i<3; i++)
    {
        for(size_t j = 0; j<3; j++)
        {
            curr = &(lists[(3*lg + i)*9 + 3*cg + j]);
            del(curr,nb ,len(curr));
        }
    }
    i = 0;
    while(i < lg*3 - 1 && diff)
    {
        curr = &(grid[i*9 + c]);
        del(curr, nb, len(curr));
        i++;
    }
    i = lg*3 + 2;
    while(i < 9 && diff)
    {
        curr = &(grid[i*9 + c]);
        del(curr, nb, len(curr));
        i++;
    }
    i = 0;
    while(i < cg*3 - 1 && diff)
    {
        curr = &(grid[l*9 + i]);
        del(curr, nb, len(curr));
        i++;
    }
    i = cg*3 + 2;
    while(i < 9 && diff)
    {
        curr = &(grid[l*9 + i]);
        del(curr, nb, len(curr));
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