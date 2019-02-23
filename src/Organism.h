/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Cell;
#include "Cell.h"

/**
 * The organism class is a superclass for the Ant and Doodlebug class, and should never be instantiated as an actual object.
 */
class Organism {
public:
	Organism();
	virtual bool move(Cell* newCell)=0;
	virtual bool breed(Cell* newCell)=0;
	virtual int getRow()=0;
	virtual int getCol()=0;
	virtual ~Organism();
	void setStepRan(bool b);
	bool getStepRan();
protected:
	int timeStepsSurvived;
	bool stepRan;
};

#endif /* ORGANISM_H_ */
