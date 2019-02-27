/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Doodlebug.h"

/**
 * Constructs a new grid
 * @param nSquaresOnASide the diameter of the board, default is 20
 * @param doodlebugs the number of doodlebugs on the board, default is 5
 * @param ants the number of ants on the board, default is 100
 * @param g the number of generations to run, default is 1000
 * @param seed the seed to use when randomly generating the board, default is 1
 * @param stop if nonzero, then the program waits for user input before running another
 * generation. default is 0.
 */
Grid::Grid(int nSquaresOnASide, int doodlebugs, int ants, int g,int seed, int stop)
{
	sizeOfGrid = nSquaresOnASide; //initialize size of grid
	gens = g;
	doodleLeft = doodlebugs;
	antsLeft = ants;
	pause = stop != 0;
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [sizeOfGrid];  //first allocate array of row pointers

	for(int i=0 ; i < sizeOfGrid ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[sizeOfGrid]; // allocate memory for columns in each row
	}
	for(int i = 0; i < sizeOfGrid; i++) {
		for(int j = 0; j < sizeOfGrid; j++) {
			myGridCells_ptr_array[i][j].setPosition(i, j);
			//sets all the cells up such that they know their position
		}
	}
	setUpGrid(doodlebugs,doodlebug);
	setUpGrid(ants,ant);
}

/**
 * Sets the occupant of the cell at r,c to be either an ant, doodlebug, or empty
 * @param r the row in the cell array
 * @param c the column in the cell array
 * @param g the status to set that cell to
 * @return true if occupant set, false if fail
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{
	return myGridCells_ptr_array[r][c].setOccupant(g);
}

/**
 * Returns the cell occupant at the cell denoted by r,c
 * @param r the row of the cell
 * @param c the column of the cell
 * @return the occupationStatus of that cell (either empty, ant, or doodlebug)
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}

/**
 * Finds a cell either below, above, to the right, or to the left of the cell denoted by r,c. It is looking for the type of cell denoted by the occupation status.
 * @param r the row of the cell to look around
 * @param c the column of the cell to look around
 * @param toLookFor the type of cell we are looking for, either an empty one, ant one, or a doodlebug one
 * @return a pointer to the cell that the function deems is an "open" cell based on the occupationStatus. If the function
 * does not find a cell, it will return a nullptr.
 */
Cell* Grid::findOpenCell(int r, int c, occupationStatus toLookFor) {
	bool done = false;
	Cell* ret = nullptr;
	bool upDone = !isValidLocation(r-1,c);
	bool downDone = !isValidLocation(r+1,c);
	bool leftDone = !isValidLocation(r,c-1);
	bool rightDone = !isValidLocation(r,c+1);
	//if one of the locations is not valid, the boolean will already be true so the program won't check that direction.
	while(!done) {
		int random = rand()%4; //random int 0->3
		if(random == 0 && !downDone) {
			if(getCellOccupant(r+1, c) == toLookFor) {
				ret = &myGridCells_ptr_array[r+1][c];
				done = true; //if we find something there, then we set return value to it and stop the program
			}
			else downDone = true; //if we don't find something, then this direction is clear and we can ignore it.
			//the other else-ifs serve the same purpose for the other directions.
		}
		else if(random == 1 && !upDone) {
			if(getCellOccupant(r-1, c) == toLookFor) {
				ret = &myGridCells_ptr_array[r-1][c];
				done = true;
			}
			else upDone = true;
		}
		else if(random == 2 && !rightDone) {
			if(getCellOccupant(r, c+1) == toLookFor) {
				ret = &myGridCells_ptr_array[r][c+1];
				done = true;
			}
			else rightDone = true;
		}
		else if(random == 3 && !leftDone) {
			if(getCellOccupant(r, c-1) == toLookFor) {
				ret = &myGridCells_ptr_array[r][c-1];
				done = true;
			}
			else leftDone = true;
		}
		else if(downDone && leftDone && rightDone && upDone) done = true; //if all directions have been looked at, we are done and will return a nullptr.
	}
	return ret;
}

/**
 * Runs the grid for however many generations specified or until an end condition is met.
 * @return the number of generations ran
 */
int Grid::run() {
	bool done = false; //are we done or not
	int g = 1; //number of generations ran
	printGrid();
	while(!done) {
		if(antsLeft <= 0 || doodleLeft <= 0) done = true; //if no more ants or doodlebugs, we're done
		if(!done) {
			if(pause != 0)
			{
				std::cout << "Paused waiting for input." << std::endl;
				getc(stdin);//just waits for user input
			}
			//this set of for loops goes thru the grid and steps all of the doodlebugs
			for(int i = 0; i < sizeOfGrid; i++) {
				for(int j = 0; j < sizeOfGrid; j++) {
					Cell* theCell = &myGridCells_ptr_array[i][j];
					//if the cell has a doodlebug and it hasn't already been touched by the program
					if(theCell->getOccupant() == doodlebug && !theCell->getCellOwner()->getStepRan()) {
						//MOVING
						Cell* moveTo = findOpenCell(i,j,ant); //look for ant to eat!
						if(moveTo != nullptr) {
							moveTo->getCellOwner()->~Organism();
							antsLeft--; //if found, decrement the number of ants on the board
						}
						else {
							moveTo = findOpenCell(i,j,empty); //otherwise, if not found, look for an empty cell
						}
						if(moveTo != nullptr) {
							Organism* guy = theCell->getCellOwner();
							theCell->setOccupant(empty); //set the current cell we're in to be empty
							guy->move(moveTo); //move to the open cell
						}
						else {
							moveTo = theCell; //if we couldn't move, moveTo is just the cell itself.
						}
						//STARVING
						class Doodlebug* owner = (class Doodlebug*)moveTo->getCellOwner();
						bool didStarve = owner->starve(); //check to see if we starve or not
						if(didStarve) {
							owner->~Organism(); //if we starve, delete this organism
							moveTo->setOccupant(empty); //get rid of the occupant of the cell
							doodleLeft--; //decrement amount of doodlebugs on the board
						}
						//BREEDING
						else { //if we don't starve
							Cell* breedSpot = findOpenCell(moveTo->getRow(), moveTo->getCol(), empty); //look for a breeding spot
							if(breedSpot != nullptr) {
								bool hasBred = moveTo->getCellOwner()->breed(breedSpot); //try to breed
								if(hasBred) doodleLeft++; //increase number of doodlebugs if we actually bred
							}
						}
					}

				}
			}
			//this set of for loops go through the grid and step the ants
			for(int i = 0; i < sizeOfGrid; i++) {
				for(int j = 0; j < sizeOfGrid; j++) {
					Cell* theCell = &myGridCells_ptr_array[i][j];
					//if the cell has an ant and the ant hasn't been touched by the program already
					if(theCell->getOccupant() == ant && !theCell->getCellOwner()->getStepRan()) {
						//MOVING
						Cell* moveTo = findOpenCell(i,j,empty); //find an empty cell to move to
						if(moveTo != nullptr) {
							Organism* ant = theCell->getCellOwner();
							theCell->setOccupant(empty);
							ant->move(moveTo); //if found, move to the cell in the same way doodlebugs do
						}
						else {
							moveTo = theCell; //if not found, the cell we moved to was the current cell.
						}
						//BREEDING
						Cell* breedSpot = findOpenCell(moveTo->getRow(), moveTo->getCol(), empty); //find a breeding spot
						if(breedSpot != nullptr) {
							bool didBreed = moveTo->getCellOwner()->breed(breedSpot); //try to breed
							if(didBreed) antsLeft++; //increase number of ants on the board if it bred
						}
					}
				}
			}
			//loop through and set all stepRans to false so they run in the next step
			for(int i = 0; i < sizeOfGrid; i++) {
				for(int j = 0; j < sizeOfGrid; j++) {
					Cell* theCell = &myGridCells_ptr_array[i][j];
					if(theCell->getOccupant() != empty) {
						theCell->getCellOwner()->setStepRan(false);
					}
				}
			}
		}
		g++;
		if(g == gens) done = true; //if we have ran through the amount of generations specified, then we're done
		printGrid(); //print the grid.
	}
	return g;
}

/**
 * Prints the current state of the grid, with doodlebugs denoted as "x" and ants denoted as "o"
 */
void Grid::printGrid() {
	for(int i = 0; i < sizeOfGrid; i++) {
		for(int j = 0; j < sizeOfGrid; j++) {
			Cell theCell = myGridCells_ptr_array[i][j];
			if(theCell.getOccupant() == doodlebug) std::cout << "x"; //if doodlebug, print x
			else if(theCell.getOccupant() == ant) std::cout << "o"; //if ant, print o
			else std::cout << " "; //if empty, print a blank
		}
		std::cout << std::endl; //break between rows
	}
	std::cout << std::endl; //break between grids
}

/**
 * Checks to see if the row and column are valid locations on this grid
 * @param r the row to check
 * @param c the column to check
 * @return true if it is a valid point (0 <= r,c < sizeOfGrid), false if not
 */
bool Grid::isValidLocation(int r, int c) {
	bool retValue = true;
	if(r >= sizeOfGrid || c >= sizeOfGrid || c < 0 || r < 0) retValue = false;
	return retValue;
}

/**
 * Gets the current number of ants on the board
 * @return the amount of ants on the board
 */
int Grid::getAntCount() {
	return antsLeft;
}

/**
 * Gets the current number of doodlebugs on the board
 * @return the amount of doodlebugs on the board
 */
int Grid::getDoodleCount() {
	return doodleLeft;
}

/**
 * Sets up the grid with an amount of a certain occupationStatus in random locations.
 * @param number the amount of entities to put on the grid
 * @param toSetUp the kind of entity to put on the grid (ant or doodlebug?)
 */
void Grid::setUpGrid(int number, occupationStatus toSetUp) {
	while(number > 0) {
		int row = rand()%sizeOfGrid;
		int col = rand()%sizeOfGrid;
		//get random row and column
		if(isValidLocation(row,col) && myGridCells_ptr_array[row][col].getOccupant() == empty) { //if its a valid location and doesnt have an occupant already
			myGridCells_ptr_array[row][col].setOccupant(toSetUp);
			number--; //put it in the array and decrement the number we have to set up
		}
	}
	//finishes once we have set up number amount of toSetUp.
}

/**
 * Destroys this object.
 */
Grid::~Grid() {
	for(int i = 0; i < sizeOfGrid; i++) {
		for(int j = 0; j < sizeOfGrid; j++) {
			myGridCells_ptr_array[i][j].~Cell();
		}
	}
}

