/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"

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
}

bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{
	return myGridCells_ptr_array[r][c].setOccupant(g);
}

occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}

Cell* Grid::findOpenCell(int r, int c) {
	bool done = false;
	bool upDone = false;
	bool downDone = false;
	bool leftDone = false;
	bool rightDone = false;
	while(!done) {
		int random = rand()%4;
		if(random == 0 && !downDone && isValidLocation(r+1,c)) {
			if(getCellOccupant(r+1, c) == empty) return &myGridCells_ptr_array[r+1][c];
			else downDone = true;
		}
		else if(random == 1 && !upDone && isValidLocation(r-1,c)) {
			if(getCellOccupant(r-1, c) == empty) return &myGridCells_ptr_array[r-1][c];
			else upDone = true;
		}
		else if(random == 2 && !rightDone && isValidLocation(r,c+1)) {
			if(getCellOccupant(r, c+1) == empty) return &myGridCells_ptr_array[r][c+1];
			else rightDone = true;
		}
		else if(random == 3 && !leftDone && isValidLocation(r,c-1)) {
			if(getCellOccupant(r, c-1) == empty) return &myGridCells_ptr_array[r][c-1];
			else leftDone = true;
		}
		else return nullptr;
	}
}

bool Grid::run() {
	bool done = false;
	int g = 0;
	while(!done) {
		bool antsDead = true;
		bool doodleDead = true;
		for(int i = 0; i < sizeOfGrid; i++) {
			for(int j = 0; j < sizeOfGrid; j++) {
				if(getCellOccupant(i,j) == ant) antsDead = false;
				else if(getCellOccupant(i,j) == doodlebug) doodleDead = false;
				//making sure there is an ant and/or a doodlebug on the grid still
			}
		}
		if(antsDead || doodleDead) done = true; //if no more ants or doodlebugs, we're done
		if(!done) {
			for(int i = 0; i < sizeOfGrid; i++) {
				for(int j = 0; j < sizeOfGrid; j++) {
					Cell* theCell = &myGridCells_ptr_array[i][j];
					if(theCell->getOccupant() == doodlebug) {
					}
				}
			}
			for(int i = 0; i < sizeOfGrid; i++) {
				for(int j = 0; j < sizeOfGrid; j++) {
					//loop thru and step all of the ants
				}
			}
		}
		g++;
		if(g == gens) done = true;
	}
	return done;
}

void Grid::printEnding() {

}

void Grid::printGrid() {

}

bool Grid::isValidLocation(int r, int c) {
	bool retValue = true;
	if(r >= sizeOfGrid || c >= sizeOfGrid || c < 0 || r < 0) retValue = false;
	return retValue;
}

Grid::~Grid() {

	for(int r=0; r < sizeOfGrid; r++)
	{
		for(int c=0; c < sizeOfGrid; c++)
		{
			//cout << "Before freeing" << r << c << endl;
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
	//myGridCells_ptr_array = (Cell**)nullptr;
}

