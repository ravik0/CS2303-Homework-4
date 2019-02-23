/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Doodlebug.h"

/**
 * Creates a new Doodlebug, which is also an Organism
 * @param r the row that this doodlebug resides in
 * @param c the column that this doodlebug resides in
 */
Doodlebug::Doodlebug(int r, int c) : Organism() {
	row = r;
	column = c;
	timeStepsSurvived = 0;
}

/**
 * Moves the doodlebug to the cell specified
 * NOTE: The user must remove this doodlebug from its current cell ~before~ moving it to the new cell, as the doodlebug itself does
 * not keep track of what cell it is in, that is the grid's job
 * @param newCell the new cell to put the doodlebug in
 * @return true, it will not fail to move.
 */
bool Doodlebug::move(Cell* newCell)
{
	bool status = true;
	if(newCell->getOccupant() != ant) {
		stepsWithoutEating++; //if we are moving to an empty square, it hasn't eaten 1 more tick
	}
	else if(newCell->getOccupant() == ant) {
		stepsWithoutEating = 0; //if its moving to an ant square, it has eaten
	}
	if(status) {
		newCell->setOccupant(doodlebug); //set cell occupant to a doodlebug
		newCell->setOrganism(this); //set cell organism to this
		row = newCell->getRow();
		column = newCell -> getCol(); //update doodlebug's row and column
	}
	stepRan = true; //notify the program that this doodlebug has been used already this generation
	timeStepsSurvived++; //increase the amount of time that this doodlebug has survived
	return status;
}

/**
 * Breeds a new doodlebug into the cell denoted by newCell if the doodlebug is eligable to breed.
 * @param newCell the cell to breed into
 * @return true if bred, false if it didn't
 */
bool Doodlebug::breed(Cell* newCell)
{
	bool status = true;
	if(timeStepsSurvived < 8 || newCell->getOccupant() != empty) status = false;
	else {
		newCell->setOccupant(doodlebug);
		timeStepsSurvived = 0;
		newCell->getCellOwner()->setStepRan(true);
	}
	return status;
}

/**
 * Checks to see if the doodlebug starves
 * NOTE: The user must deal with actually killing off the doodlebug, as this only checks to see if the doodlebug is eligable to starve.
 * @return true if the doodlebug will starve, false if it is fine
 */
bool Doodlebug::starve() {
	bool didStarve = false;
	if(stepsWithoutEating >= 3) {
		didStarve = true;
	}
	return didStarve;
}

/**
 * Gets the row of the cell that this doodlebug resides in
 * @return the row
 */
int Doodlebug::getRow() {
	return row;
}

/**
 * Gets the column of the cell that this doodlebug resides in
 * @return the column
 */
int Doodlebug::getCol() {
	return column;
}

/**
 * Destroys the doodlebug instance.
 */
Doodlebug::~Doodlebug() {

}

