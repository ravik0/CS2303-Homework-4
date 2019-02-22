/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Ant.h"
#include "Cell.h"

Ant::Ant(int r, int c) : Organism(true)
{
	row = r;
	col = c;
}

bool Ant::move(Cell* newCell)
{
	bool status = true;
	return status;
}

bool Ant::breed()
{
	bool status = true;
	return status;
}

bool Ant::starve() {
	return false;
}

int Ant::getCol() {
	return col;
}

int Ant::getRow() {
	return row;
}
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

