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

Cell::Cell(int r, int c) {
	guest = empty;
	guy = nullptr;
	row = r;
	column = c;
}

bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;
	if(guest==empty)
	{
		guest = g;
		if(guest == ant) {
			guy = new Ant(row, column);
		}
		else {
			guy = new Doodlebug(row, column);
		}
	}
	else if(g == empty) {
		guy = nullptr;
		guest = g;
		result = true;
	}
	return result;
}

occupationStatus Cell::getOccupant()
{
	return guest;
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

