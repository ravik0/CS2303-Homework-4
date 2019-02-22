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


class Cell {
public:
	Cell();
	void setPosition(int r, int c);
	bool setOccupant(occupationStatus g);
	occupationStatus getOccupant();
	Organism* getCellOwner();
	virtual ~Cell();
	int getRow();
	int getCol();
private:
	occupationStatus guest;
	Organism* guy;
	int row;
	int column;
};

#endif /* CELL_H_ */
