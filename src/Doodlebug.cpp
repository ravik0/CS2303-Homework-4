/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Doodlebug.h"

Doodlebug::Doodlebug(int r, int c) : Organism(false) {
	row = r;
	column = c;
	timeStepsSurvived = 0;
}

bool Doodlebug::move(Cell* newCell)
{
	bool status = true;
	if(newCell->getOccupant() == doodlebug) {
		status = false;
	}
	else if(newCell->getOccupant() == empty) {
		stepsWithoutEating++;
	}
	else if(newCell->getOccupant() == ant) {
		stepsWithoutEating = 0;
	}
	if(status) {
		newCell->setOccupant(doodlebug);
		newCell->setOrganism(this);
		row = newCell->getRow();
		column = newCell -> getCol();
	}
	stepRan = true;
	timeStepsSurvived++;
	return status;
}

bool Doodlebug::breed(Cell* newCell)
{
	bool status = true;
	if(newCell->getOccupant() == ant) status = false;
	else {
		newCell->setOccupant(doodlebug);
		timeStepsSurvived = 0;
		newCell->getCellOwner()->setStepRan(true);
	}
	return status;
}
bool Doodlebug::canBreed() {
	return timeStepsSurvived >= 8;
}
bool Doodlebug::starve() {
	bool didStarve = false;
	if(stepsWithoutEating >= 3) {
		didStarve = true;
	}
	return didStarve;
}

int Doodlebug::getRow() {
	return row;
}

int Doodlebug::getCol() {
	return column;
}
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

