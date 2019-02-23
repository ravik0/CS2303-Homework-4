/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"

/**
 * Creates a new Organism
 */
Organism::Organism() {
	timeStepsSurvived = 0;
	stepRan = false;
}

/**
 * Sets the stepRan boolean, which is a boolean that tells you whether this organism has been touched by the program in this generation
 * @param b the boolean to set it to
 */
void Organism::setStepRan(bool b) {
	stepRan = b;
}

/**
 * Gets the stepRan boolean, which is a boolean that tells you whether this organism has been touched by the program in this generation
 * @return true if the program has touched this organism this generation, false otherwise
 */
bool Organism::getStepRan() {
	return stepRan;
}

/**
 * Destroys the organism
 */
Organism::~Organism() {

}

