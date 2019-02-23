/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_
#include "Cell.h"
#include <iostream>

/**
 * The grid class contains the grid for the simulation, and handles running all of the calculations for the simulation as well.
 */
class Grid {
public:
	Grid(int nSquaresOnASide = 20, int doodlebugs = 5, int ants = 100, int g = 1000, int seed = 1, int pause = 0);
	virtual ~Grid();
	int run();
	int getAntCount();
	int getDoodleCount();
	void printGrid();
	/**
	 * Function to test whether findEmptyCell works
	 * @return true if findEmptyCell works, false if failed
	 */
	static bool testFindEmptyCell() {
		std::cout << "Running testFindEmptyCell" << std::endl;
		bool ok1 = false;
		bool ok2 = false;
		bool ok3 = false;
		Grid* theGrid = new Grid(5, 0, 0);
		theGrid->setCellOccupant(3, 2, ant);
		theGrid->setCellOccupant(1,2,ant);
		theGrid->setCellOccupant(2,3,ant);
		Cell* emptyCell = theGrid->findOpenCell(2, 2, empty);
		if(emptyCell->getRow() == 2 && emptyCell->getCol() == 1) ok1 = true;
		theGrid->setCellOccupant(0,1,ant);
		theGrid->setCellOccupant(1,0,ant);
		Cell* emptyCell2 = theGrid->findOpenCell(0,0, empty);
		if(emptyCell2 == nullptr) ok2 = true;
		Cell* antCell = theGrid->findOpenCell(3,3,ant);
		if((antCell->getRow() == 3 && antCell->getCol() == 2) ||
				(antCell->getRow() == 2 && antCell->getCol() == 3)) ok3 = true;
		theGrid->printGrid();
		theGrid->~Grid();
		return ok1 && ok2 && ok3;
	}

	/**
	 * Function to test whether isValidLocation works
	 * @return true if works, false if fail
	 */
	static bool testValidLocation() {
		std::cout << "Running testValidLocation" << std::endl;
		bool ok1 = false;
		bool ok2 = false;
		bool ok3 = false;
		Grid* myGrid = new Grid(5,0,0);
		ok1 = myGrid->isValidLocation(0, 0);
		ok2 = !myGrid->isValidLocation(-1,4);
		ok3 = !myGrid->isValidLocation(3,5);
		myGrid->~Grid();
		return ok1 && ok2 && ok3;
	}

	/**
	 * Tests to make sure that getOccupant and setOccupant in Grid both work
	 * @return true if pass, false if fail
	 */
	static bool testGetSetOccupant() {
		std::cout << "Running testGetSetOccupant()" << std::endl;
		Grid* myGrid = new Grid(5,0,0);
		myGrid->setCellOccupant(3, 1, ant);
		myGrid->setCellOccupant(2,1,doodlebug);
		myGrid->setCellOccupant(0,0,ant);
		myGrid->setCellOccupant(4,4,ant);
		myGrid->printGrid();
		bool ok1 = myGrid->getCellOccupant(3, 1) == ant;
		bool ok2 = myGrid->getCellOccupant(0, 0) == ant;
		bool ok3 = myGrid->getCellOccupant(4,4) == ant;
		bool ok4 = myGrid->getCellOccupant(2,1) == doodlebug;
		bool ok5 = myGrid->getCellOccupant(2,2) == empty;
		std::cout << "0 means empty, 1 means ant, 2 means doodlebug" << std::endl;
		std::cout << "Cell 3,1 should have occupant ant, has occupant " << myGrid->getCellOccupant(3,1) << std::endl;
		std::cout << "Cell 0,0 should have occupant ant, has occupant " << myGrid->getCellOccupant(0,0) << std::endl;
		std::cout << "Cell 4,4 should have occupant ant, has occupant " << myGrid->getCellOccupant(4,4) << std::endl;
		std::cout << "Cell 2,1 should have occupant doodlebug, has occupant " << myGrid->getCellOccupant(2,1) << std::endl;
		std::cout << "Cell 2,2 should have occupant empty, has occupant " << myGrid->getCellOccupant(2,2) << std::endl;
		myGrid->~Grid();
		return ok1 && ok2 && ok3 && ok4 && ok5;
	}
private:
	int sizeOfGrid;
	int gens;
	int doodleLeft;
	int antsLeft;
	bool pause;
	Cell** myGridCells_ptr_array = nullptr;
	void setUpGrid(int number, occupationStatus toSetUp);
	Cell* findOpenCell(int r, int c, occupationStatus toLookFor);
	bool isValidLocation(int r, int c);
	bool setCellOccupant(int r, int c, occupationStatus g);
	occupationStatus getCellOccupant(int r, int c);
};

#endif /* GRID_H_ */
