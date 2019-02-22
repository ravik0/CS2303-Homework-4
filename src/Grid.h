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
	Grid();
	Grid(int nSquaresOnASide);
	bool setCellOccupant(int r, int c, occupationStatus g);
	occupationStatus getCellOccupant(int r, int c);
	virtual ~Grid();
	Cell* findOpenCell(int r, int c);
	bool isValidLocation(int r, int c);
	bool run();
	bool printEnding();
private:
	int sizeOfGrid;
};

#endif /* GRID_H_ */
