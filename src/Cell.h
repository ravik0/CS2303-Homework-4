/*
 * Cell.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef CELL_H_
#define CELL_H_
class Organism;
#include "Organism.h"

enum occupationStatus { empty, ant, doodlebug};

/**
 * The cell class contains the organism that is at the position in the grid, as well as the type of organism that is in it.
 */
class Cell {
public:
	Cell();
	void setPosition(int r, int c);
	bool setOccupant(occupationStatus g);
	occupationStatus getOccupant();
	Organism* getCellOwner();
	virtual ~Cell();
	void setOrganism(Organism* set);
	int getRow();
	int getCol();
private:
	occupationStatus guest;
	Organism* guy;
	int row;
	int column;
};

#endif /* CELL_H_ */
