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
	bool isPrey();
	virtual bool move(Cell* newCell)=0;
	virtual bool breed()=0;
	virtual bool starve()=0;
	virtual int getRow()=0;
	virtual int getCol()=0;
	void setAmAnt(bool b);
	virtual ~Organism();
	void setStepRan(bool b);
	bool getStepRan();
private:
	bool amAnt;
	bool stepRan;
protected:
	int timeStepsSurvived;
};

#endif /* ORGANISM_H_ */
