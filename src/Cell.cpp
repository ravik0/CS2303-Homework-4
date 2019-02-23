/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include "Cell.h"
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"

/**
 * Creates a new cell
 */
Cell::Cell() {
	guest = empty;
	guy = nullptr;
	row = -1;
	column = -1;
}

/**
 * Sets the position of this cell to a certain row and column
 * @param r the row of this cell
 * @param c the column of this cell
 */
void Cell::setPosition(int r, int c) {
	row = r;
	column = c;
}

/**
 * Returns a pointer to the organism that this cell represents.
 * @return the organism that resides in this cell
 */
Organism* Cell::getCellOwner() {
	return guy;
}

/**
 * Sets the occupant type of this cell
 * Setting it to ant will create a new ant in the organism space
 * Setting it to doodlebug will create a new doodlebug in the organism space
 * Setting it to empty will get rid of the entity in the organism space
 * @param g the occupation status that this cell will take on
 * @return true
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;
	guest = g;
	if(guest == ant) {
		guy = new Ant(row, column);
	}
	else if(guest == doodlebug){
		guy = new Doodlebug(row, column);
	}
	if(g == empty) {
		guy = nullptr;
		guest = g;
		result = true;
	}
	return result;
}

/**
 * Sets the organism of this cell to a certain organism
 * @param set the organism to let live in this cell
 */
void Cell::setOrganism(Organism* set) {
	guy = set;
}

/**
 * Returns the occupation status of this cell
 * @return empty, ant, or doodlebug
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}

/**
 * Gets the row of this cell
 * @return the row
 */
int Cell::getRow() {
	return row;
}

/**
 * Gets the column of this cell
 * @return the column
 */
int Cell::getCol() {
	return column;
}

/**
 * Destroys the instance of this cell.
 */
Cell::~Cell() {

}

