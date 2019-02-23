/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_
#include "Cell.h"

/**
 * The grid class contains the grid for the simulation, and handles running all of the calculations for the simulation as well.
 */
class Grid {
public:
	Grid(int nSquaresOnASide = 20, int doodlebugs = 5, int ants = 100, int g = 1000, int seed = 1, int pause = 0);
	bool setCellOccupant(int r, int c, occupationStatus g);
	occupationStatus getCellOccupant(int r, int c);
	virtual ~Grid();
	Cell* findOpenCell(int r, int c, occupationStatus toLookFor);
	bool isValidLocation(int r, int c);
	int run();
	int getAntCount();
	int getDoodleCount();
	void printGrid();
	void setUpGrid(int number, occupationStatus toSetUp);
private:
	int sizeOfGrid;
	int gens;
	int doodleLeft;
	int antsLeft;
	bool pause;
	Cell** myGridCells_ptr_array = nullptr;
};

#endif /* GRID_H_ */
