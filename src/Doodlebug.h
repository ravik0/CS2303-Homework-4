/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_
#include "Organism.h"
#include "Cell.h"

/**
 * The doodlebug class is a subclass of the Organism class, is eligable to breed after surviving 8 turns, can starve after not eating for 3 turns,
 * can eat ants by moving into the cell that they are in, and will always move before the ants.
 */
class Doodlebug: public Organism {
public:
	Doodlebug(int r, int c);
	bool move(Cell* newCell);
	bool breed(Cell* newCell);
	bool starve();
	int getRow();
	int getCol();
	~Doodlebug();
private:
	int row;
	int column;
	int stepsWithoutEating = 0;
};

#endif /* DOODLEBUG_H_ */
