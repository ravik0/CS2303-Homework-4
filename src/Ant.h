/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Cell.h"

/**
 * The Ant class is a subclass of the Organism class, and is eligable to breed after it is alive for 3 timesteps, can be eaten by doodlebugs,
 * and only moves into unoccupied cells.
 */
class Ant: public Organism {
private:
	int row = 0;
	int col = 0;

public:
	Ant(int r=0, int c = 0);
	bool move(Cell* newCell);
	bool breed(Cell* newCell);
	int getRow();
	int getCol();
	~Ant();
};

#endif /* ANT_H_ */
