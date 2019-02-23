/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"

Organism::Organism(bool b) {
	timeStepsSurvived = 0;
	stepRan = false;
}

void Organism::setStepRan(bool b) {
	stepRan = b;
}

bool Organism::getStepRan() {
	return stepRan;
}

Organism::~Organism() {
	delete this;
}

