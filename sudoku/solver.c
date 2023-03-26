#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <err.h>
#include "sudoku.h"

// Generates the possibilities lists of each cell
pos_list* generate_lists(char* grid)
{
    char** curr;
    char poss[9] = {0};
    size_t i = 0;
    for(size_t l = 0; i < 9; i++)
    {
        for(size_t c = 0; i < 9; i++)
        {
            for(size_t num = 1; num < 10; num++)
            {
                char found = 0;
                if(grid[l*9 +c] == 0)
                {
                    char lg = l/3;
                    char cg = c/3;
                    for(i = 0; i<3; i++)
                    {
                        for(size_t j = 0; j<3; j++)
                        {
                            found = num == grid[(3*lg + i)*9 + 3*cg + j];
                        }
                    }
                    i = 0;
                    while(i < lg*3 - 1 && !found)
                    {
                        found = num == grid[i*9 + c];
                        i++;
                    }
                    i = lg*3 + 2;
                    while(i < 9 && !found)
                    {
                        found = num == grid[i*9 + c];
                        i++;
                    }
                    i = 0;
                    while(i < cg*3 - 1 && !found)
                    {
                        found = num == grid[l*9 + i];
                        i++;
                    }
                    i = cg*3 + 2;
                    while(i < 9 && !found)
                    {
                        found = num == grid[l*9 + i];
                        i++;
                    }
                }
            }
        }
    }
    char* res = calloc(9, sizeof(char));
    size_t size = 0;
    for(i = 0; i < 9; i++)
    {
        if(!poss[i])
        {
            res[size] = 1;
            size++;
        }
    }
    res = realloc(res, size*sizeof(char));
}

size_t len(char* list)
{
    //TODO
}

//Removes an element "val" from a list of chars
void del(pos_list* arr, char val)
{
    size_t pos = 0;
    while(pos < 9 && arr->list[pos] != val)
    {
        pos++;
    }
    if(pos >= 9)
    {
        warnx("No deletion occured");
        return;
    }
    for(size_t i = pos-1; i < arr->len - 1; i++)
    {
        arr->list[i] = arr->list[i + 1];
    }
    arr->len--;
    *(arr->list) = realloc(*list, (arr->len)*sizeof(char));
}

//Update the lists of possibilities
void update_lists(char* grid, pos_list* lists, char l, char c, char nb)
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
    while(i < lg*3 - 1)
    {
        curr = &(grid[i*9 + c]);
        del(curr, nb, len(curr));
        i++;
    }
    i = lg*3 + 2;
    while(i < 9)
    {
        curr = &(grid[i*9 + c]);
        del(curr, nb, len(curr));
        i++;
    }
    i = 0;
    while(i < cg*3 - 1)
    {
        curr = &(grid[l*9 + i]);
        del(curr, nb, len(curr));
        i++;
    }
    i = cg*3 + 2;
    while(i < 9)
    {
        curr = &(grid[l*9 + i]);
        del(curr, nb, len(curr));
        i++;
    }
}

//Gets a position for one of the cells with the minimal possibilities
char random_min_pos(pos_list* lists)
{
    //TODO
}

//The solver of the Sudoku, using an implementation of the Wave Collapse function
char* collapse_solver(char* grid, char alr_filled)
{
    pos_list* lists = generate_lists(grid);
    char* list;
    char to_fill = 81 - alr_filled;
    size_t len;
    char nb;
    char min;
    srand(time(NULL));
    while(to_fill > 0)
    {
        min = random_min_pos(lists);
        list = (lists[min]).list;
        len = len(list);
        nb  = list[(rand() % len)];
        grid[min] = nb;
        update_lists(grid, lists, min / 9, min % 9, nb);
        to_fill--;
    }
    return grid;
}
