/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Doodlebug: public Organism {
public:
	Doodlebug();
	Doodlebug(int r, int c);
	bool move();
	bool breed();
	bool eat();
	bool starve();
	virtual ~Doodlebug();
private:
	int row;
	int column;
	int stepsWithoutEating = 0;
};

#endif /* DOODLEBUG_H_ */
