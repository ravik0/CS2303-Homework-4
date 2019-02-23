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
		}
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

Cell* Grid::findOpenCell(int r, int c, occupationStatus toLookFor) {
	bool done = false;
	bool upDone = false;
	bool downDone = false;
	bool leftDone = false;
	bool rightDone = false;
	while(!done) {
		int random = rand()%4;
		if(random == 0 && !downDone && isValidLocation(r+1,c)) {
			if(getCellOccupant(r+1, c) == toLookFor) return &myGridCells_ptr_array[r+1][c];
			else downDone = true;
		}
		else if(random == 1 && !upDone && isValidLocation(r-1,c)) {
			if(getCellOccupant(r-1, c) == toLookFor) return &myGridCells_ptr_array[r-1][c];
			else upDone = true;
		}
		else if(random == 2 && !rightDone && isValidLocation(r,c+1)) {
			if(getCellOccupant(r, c+1) == toLookFor) return &myGridCells_ptr_array[r][c+1];
			else rightDone = true;
		}
		else if(random == 3 && !leftDone && isValidLocation(r,c-1)) {
			if(getCellOccupant(r, c-1) == toLookFor) return &myGridCells_ptr_array[r][c-1];
			else leftDone = true;
		}
		else done = true;
	}
	return nullptr;
}

int Grid::run() {
	bool done = false;
	int g = 0;
	while(!done) {
		if(antsLeft <= 0 || doodleLeft <= 0) done = true; //if no more ants or doodlebugs, we're done
		if(!done) {
			for(int i = 0; i < sizeOfGrid; i++) {
				for(int j = 0; j < sizeOfGrid; j++) {
					Cell* theCell = &myGridCells_ptr_array[i][j];
					if(theCell->getOccupant() == doodlebug && !theCell->getCellOwner()->getStepRan()) {
						//MOVING
						Cell* moveTo = findOpenCell(i,j,ant);
						if(moveTo != nullptr) {
							antsLeft--;
						}
						else {
							moveTo = findOpenCell(i,j,empty);
						}
						if(moveTo != nullptr) {
							Organism* guy = theCell->getCellOwner();
							theCell->setOccupant(empty);
							guy->move(moveTo);
						}
						else {
							moveTo = theCell;
						}
						//STARVING
						class Doodlebug* owner = (class Doodlebug*)moveTo->getCellOwner();
						bool didStarve = owner->starve();
						if(didStarve) {
							delete owner;
							moveTo->setOccupant(empty);
							doodleLeft--;
						}
						//BREEDING
						else {
							Cell* breedSpot = findOpenCell(moveTo->getRow(), moveTo->getCol(), empty);
							if(breedSpot != nullptr && moveTo->getCellOwner()->canBreed()) {
								moveTo->getCellOwner()->breed(breedSpot);
								doodleLeft++;
							}
						}
					}

				}
			}
			for(int i = 0; i < sizeOfGrid; i++) {
				for(int j = 0; j < sizeOfGrid; j++) {
					Cell* theCell = &myGridCells_ptr_array[i][j];
					if(theCell->getOccupant() == ant && !theCell->getCellOwner()->getStepRan()) {
						//MOVING
						Cell* moveTo = findOpenCell(i,j,empty);
						if(moveTo != nullptr) {
							Organism* ant = moveTo->getCellOwner();
							theCell->setOccupant(empty);
							ant->move(moveTo);
						}
						else {
							moveTo = theCell;
						}
						//BREEDING
						Cell* breedSpot = findOpenCell(moveTo->getRow(), moveTo->getCol(), empty);
						if(breedSpot != nullptr && moveTo->getCellOwner()->canBreed()) {
							moveTo->getCellOwner()->breed(breedSpot);
							antsLeft++;
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
		if(g == gens) done = true;
		if(!done) printGrid();
	}
	return g;
}

void Grid::printGrid() {
	for(int i = 0; i < sizeOfGrid; i++) {
		for(int j = 0; j < sizeOfGrid; j++) {
			Cell theCell = myGridCells_ptr_array[i][j];
			if(theCell.getOccupant() == doodlebug) std::cout << "x";
			else if(theCell.getOccupant() == ant) std::cout << "o";
			else std::cout << "O";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Grid::isValidLocation(int r, int c) {
	bool retValue = true;
	if(r >= sizeOfGrid || c >= sizeOfGrid || c < 0 || r < 0) retValue = false;
	return retValue;
}

Grid::~Grid() {
	delete[] myGridCells_ptr_array;
}

