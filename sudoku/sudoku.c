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

char valid(char* grid, char l, char c)
{
	size_t i;
	for(i = 0; i < l; i++)
	{
		
	}
	for(i = l+1; i < 9; i++)
	{
		
	}
	for(i = 0; i < c; i++)
	{
		
	}
	for(i = c+1; i < 9; i++)
	{
		
	}
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
			// TODO: modify so function verifies that the number added is valid and changes it if not
/* 			char valid = 0;
			while(valid == 0)
			{
				valid = 1;
			} 
*/
			grid[l*9 + c] = rand() % 9;
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
