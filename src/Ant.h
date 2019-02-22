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

class Ant: public Organism {
private:
	int row = 0;
	int col = 0;

public:
	Ant(int r=0, int c = 0);
	bool move(Cell* newCell);
	bool breed();
	bool starve();
	int getRow();
	int getCol();
	~Ant();
};

#endif /* ANT_H_ */
