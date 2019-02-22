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
}

bool Doodlebug::move(Cell* newCell)
{
	bool status = true;
	return status;
}

bool Doodlebug::breed()
{
	bool status = true;
	return status;
}
bool Doodlebug::eat()
{
	bool status = true;
	return status;
}
bool Doodlebug::starve() {
	bool didStarve = false;
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

