/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Ant.h"
#include "Cell.h"

/**
 * Creates a new ant, which is also an organism
 * @param r the row this ant resides in
 * @param c the column this ant resides in
 */
Ant::Ant(int r, int c) : Organism()
{
	row = r;
	col = c;
	timeStepsSurvived = 0;
}

/**
 * Moves the ant to the cell specified
 * NOTE: The user must remove this ant from its current cell ~before~ moving it to the new cell, as the ant itself does
 * not keep track of what cell it is in, that is the grid's job
 * @param newCell the new cell to put the ant in
 * @return true if move, false if fail
 */
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

/**
 * Breeds a new ant into the cell denoted by newCell if the ant is eligable to breed.
 * @param newCell the cell to breed into
 * @return true if bred, false if it didn't
 */
bool Ant::breed(Cell* newCell)
{
	bool status = true;
	if(timeStepsSurvived < 3 || newCell->getOccupant() != empty) status = false;
	else {
		newCell->setOccupant(ant);
		timeStepsSurvived = 0;
		newCell->getCellOwner()->setStepRan(true);
	}
	return status;
}

/**
 * Gets the column that this ant resides in
 * @return the column
 */
int Ant::getCol() {
	return col;
}

/**
 * Gets the row that this ant resides in
 * @return the row
 */
int Ant::getRow() {
	return row;
}

/**
 * Destroys the instance of the ant class
 */
Ant::~Ant() {

}

