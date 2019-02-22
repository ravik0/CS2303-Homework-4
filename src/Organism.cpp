/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"

Organism::Organism() {
	amAnt = false;
	timeStepsSurvived = 0;
	// TODO Auto-generated constructor stub

}
Organism::Organism(bool b) {
	amAnt = b;
	timeStepsSurvived = 0;
}
bool Organism::isPrey()
{
	return amAnt;
}
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}

Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

