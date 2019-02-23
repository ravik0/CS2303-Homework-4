/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Ant.h"
#include "Cell.h"

Ant::Ant(int r, int c) : Organism()
{
	row = r;
	col = c;
	timeStepsSurvived = 0;
}

bool Ant::move(Cell* newCell)
{
	bool status = true;
	if(newCell->getOccupant() != empty) {
		status = false;
	}
	if(status) {
		newCell->setOccupant(ant);
		newCell->setOrganism(this);
		row = newCell->getRow();
		col = newCell -> getCol();
	}
	stepRan = true;
	timeStepsSurvived++;
	return status;
}

bool Ant::breed(Cell* newCell)
{
	bool status = true;
	if(newCell->getOccupant() != empty) status = false;
	else {
		newCell->setOccupant(ant);
		timeStepsSurvived = 0;
		newCell->getCellOwner()->setStepRan(true);
	}
	return status;
}

bool Ant::canBreed() {
	return timeStepsSurvived >= 3;
}

int Ant::getCol() {
	return col;
}

int Ant::getRow() {
	return row;
}
Ant::~Ant() {

}

