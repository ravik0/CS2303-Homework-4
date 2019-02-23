/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Production.h"
#include "Grid.h"
#include <iostream>
#include <string>

/**
 * Sets up the program using the command line arguments
 * @param argc the number of arguments
 * @param argv[] the array of arguments given by the command line
 */
Production::Production(int argc, char* argv[]) {
	char** dump = nullptr; //a dump for all of the strtol to put in
	if(argc >= 2) {
		gridSize = strtol(argv[1], dump, 10);
	}
	if(argc >= 3) {
		doodle = strtol(argv[2], dump, 10);
	}
	if(argc >= 4) {
		ant = strtol(argv[3], dump, 10);
	}
	if(argc >= 5) {
		time_steps = strtol(argv[4], dump, 10);
	}
	if(argc >= 6) {
		seed = strtol(argv[5], dump, 10);
	}
	if(argc >= 7) {
		pause = strtol(argv[6], dump, 10);
	}
	//if argc is large enough, each of the arguments will be put in their respective places. otherwise they are initialized to default values.
}

/**
 * Runs the program using the command line arguments
 * @param argc the number of arguments
 * @param argv[] the array of arguments given by the command line
 * @return true if ran, false if failed
 */
bool Production::runProduction(int argc, char* argv[])
{
	srand(seed);
	bool result = true;
	if(doodle + ant > gridSize*gridSize) {
		std::cout << "Too many doodlebugs and ants! Please increase grid size or lower" <<
				"the amount of ants and/or doodlebugs you have!" << std::endl;
		result = false;
		//if the number of doodlebugs and ant exceed the amount of cells, return false and yell at the user.
	}
	else {
		Grid* myGrid = new Grid(gridSize, doodle, ant, time_steps, seed, pause); //create a new grid
		int gensRun = myGrid->run(); //run it
		std::cout << "Final Results" << std::endl;
		std::cout << "/Ants ";
		for(int i = 1; i < argc; i++) {
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Generations Ran: " << gensRun << std::endl;
		std::cout << "Beginning Ant Count: " << ant << ", End Ant Count: " << myGrid->getAntCount() << std::endl;
		std::cout << "Beginning Doodlebug Count: " << doodle << ", End Doodlebug Count: " << myGrid->getDoodleCount() << std::endl;
		std::cout << "Final Board Configuration" << std::endl;
		//print all of the final results
		myGrid->printGrid();
		myGrid->~Grid();
	}
	return result;
}

/**
 * Destroys the production instance.
 */
Production::~Production() {

}

