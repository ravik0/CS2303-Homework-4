/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_
#include "Cell.h"

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
private:
	int sizeOfGrid;
	int gens;
	int doodleLeft;
	int antsLeft;
	bool pause;
	Cell** myGridCells_ptr_array = nullptr;
};

#endif /* GRID_H_ */
