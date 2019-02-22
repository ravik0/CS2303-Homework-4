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
	timeStepsSurvived = 0;
}

bool Ant::move(Cell* newCell)
{
	bool status = true;
	return status;
}

bool Ant::breed(Cell* newCell)
{
	bool status = true;
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
	// TODO Auto-generated destructor stub

}

