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

Cell::Cell() {
	guest = empty;
	guy = nullptr;
	row = -1;
	column = -1;
}

void Cell::setPosition(int r, int c) {
	row = r;
	column = c;
}

Organism* Cell::getCellOwner() {
	return guy;
}

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

void Cell::setOrganism(Organism* set) {
	guy = set;
}

occupationStatus Cell::getOccupant()
{
	return guest;
}

int Cell::getRow() {
	return row;
}

int Cell::getCol() {
	return column;
}
Cell::~Cell() {

}

