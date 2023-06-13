#ifndef SOLVER
#define SOLVER

struct pos_list
{
    size_t len;
    char* list;
};

// Generates the possibilities lists of each cell
// grid = the grid wich lists are to be generated
// Returns a list of possibilities lists
pos_list* generate_lists(char* grid);

// Update the lists of possibilities
// grid = the grid
// lists = its lists of possibilities
// l = the number of the line which was collapsed
// c = the number of the column which was collapsed
// nb = the result of the collapse
void update_lists(char* grid, pos_list* lists, char l, char c, char nb);

// Gets a position for one of the cells with the minimal possibilities
// lists = the list of lists to choose from
// Returns the pos of the cell chosen
char random_min_pos(pos_list* lists);

// The solver of the Sudoku, using an implementation of the Wave Collapse function
// grid = the grid to be solved
// alr_filled = the number of cells already filled
// Returns a solved grid
char* collapse_solver(char* grid, char alr_filled);

#endif