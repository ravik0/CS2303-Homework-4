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

class Organism {
public:
	Organism(bool b = false);
	virtual bool move(Cell* newCell)=0;
	virtual bool breed(Cell* newCell)=0;
	virtual bool canBreed()=0;
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
