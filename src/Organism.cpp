/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"

Organism::Organism(bool b) {
	amAnt = b;
	timeStepsSurvived = 0;
	stepRan = false;
}

bool Organism::isPrey()
{
	return amAnt;
}

void Organism::setAmAnt(bool b)
{
	amAnt = b;
}

void Organism::setStepRan(bool b) {
	stepRan = b;
}

bool Organism::getStepRan() {
	return stepRan;
}

Organism::~Organism() {
	// TODO Auto-generated destructor stub
}

