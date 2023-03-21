#ifndef SUDOKU
#define SUDOKU


//Initialises a sudoku grid in the form of a list.
//Returns the empty grid.
char* init_empty();

//Initialises a sudoku grid in the form of a list.
//nb_in = the number of cells already filled in.
//Returns the grid partially filled.
char* init_grid(size_t nb_in);

//Saves a grid to the specified path.
//grid = the grid to save_grid.
//path = the path in which the grid will be saved.
//Returns 0 if the save is succesful, 1 else.
int save_grid(char* grid, char* path);

//Loads a grid from a specified path.
//path = the specified path.
//Return the loaded grid.
char* load_grid(char* path);

//Prints a sudoku grid on the standard output.
//grid = the grid to print.
void print_grid(char* grid);

#endif
