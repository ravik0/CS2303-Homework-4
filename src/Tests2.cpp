/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include <iostream>


Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

bool Tests2::doTests()
{
	bool results;
	bool ok1 = //gridTest();
			true;
	//populate it with ants
	bool ok2 = //makeAntsTest();
			true;
	//see whether they move
	bool ok3 = antsMoveTest();
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = //makeDoodlesTest();
			true;
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();
	bool ok11 = testFindEmptyCell();
	bool ok12 = testRun();
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12;
	return results;
}

bool Tests2::antsMoveTest()
{
	bool result = true;
	std::cout << "Running the move ants test" << std::endl;
	return result;
}
bool Tests2::antsBreedTest()
{
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;
	return result;
}
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	return result;
}
bool Tests2::doodleMoveTest()
{
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}
bool Tests2::doodleDietest()
{
	bool result = true;
	std::cout << "Running the doodlebug dies test" << std::endl;
	return result;
}
bool Tests2::testFindEmptyCell() {
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	Grid* theGrid = new Grid(5);
	theGrid->setCellOccupant(3, 2, ant);
	theGrid->setCellOccupant(1,2,ant);
	theGrid->setCellOccupant(2,3,ant);
	Cell* emptyCell = theGrid->findOpenCell(2, 2, empty);
	if(emptyCell->getRow() == 2 && emptyCell->getCol() == 1) ok1 = true;
	theGrid->setCellOccupant(0,1,ant);
	theGrid->setCellOccupant(1,0,ant);
	Cell* emptyCell2 = theGrid->findOpenCell(0,0, empty);
	if(emptyCell2 == nullptr) ok2 = true;
	Cell* antCell = theGrid->findOpenCell(3,3,ant);
	if((antCell->getRow() == 3 && antCell->getCol() == 2) ||
			(antCell->getRow() == 2 && antCell->getCol() == 3)) ok3 = true;
	return ok1 && ok2 && ok3;
}
bool Tests2::testRun() {
	bool ok1 = true;
	Grid* theGrid = new Grid(5,1,5);
	theGrid->setCellOccupant(3, 2, doodlebug);
	theGrid->setCellOccupant(0,0,ant);
	theGrid->setCellOccupant(1,0,ant);
	theGrid->setCellOccupant(2,0,ant);
	theGrid->setCellOccupant(3,0,ant);
	theGrid->setCellOccupant(4,0,ant);
	theGrid->printGrid();
	theGrid->run();
	return ok1;
}

Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

