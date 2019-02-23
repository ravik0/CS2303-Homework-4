/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>


Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

/**
 * Carries out all the tests and makes sure that they all pass
 * @return true if all test pass, false if at least one fails.
 */
bool Tests2::doTests()
{
	bool results;
	bool ok1 = Grid::testFindEmptyCell();
	if(ok1) std::cout << "findEmptyCell passed" << std::endl;
	bool ok2 = Grid::testValidLocation();
	if(ok2) std::cout << "validLocation passed" << std::endl;
	bool ok3 = testCounting();
	if(ok3) std::cout << "getAntCount and getDoodleCount passed" << std::endl;
	bool ok4 = Grid::testGetSetOccupant();
	if(ok4) std::cout << "getCellOccupant and setCellOccupant passed" << std::endl;
	bool ok5 = testDoodlebugMove();
	if(ok5) std::cout << "doodlebug's move function passed" << std::endl;
	bool ok6 = testDoodlebugBreed();
	if(ok6) std::cout << "doodlebug's breed function passed" << std::endl;
	bool ok7 = testDoodlebugStarve();
	if(ok7) std::cout << "doodlebug's starve function passed" << std::endl;
	bool ok8 = testAntMove();
	if(ok8) std::cout << "ant's move function passed" << std::endl;
	bool ok9 = testAntBreed();
	if(ok9) std::cout << "ant's breed function passed" << std::endl;
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8;
	std::cout << "tests end" << std::endl << std::endl;
	return results;
}

/**
 * Tests to make sure that getAntCount and getDoodleCount in Grid both work
 * @return true if pass, false if fail
 */
bool Tests2::testCounting() {
	std::cout << "Running testCounting" << std::endl;
	bool ok1 = false;
	bool ok2 = false;
	Grid* myGrid = new Grid(5,5,10);
	myGrid->printGrid();
	std::cout << "Number of ants: 10" << ", Number of ants getAntCount says: " << myGrid->getAntCount() << std::endl;
	std::cout << "Number of doodlebugs: 5" << ", Number of doodlebugs getDoodleCount says: " << myGrid->getDoodleCount() << std::endl;
	ok1 = myGrid->getAntCount() == 10;
	ok2 = myGrid->getDoodleCount() == 5;
	myGrid->~Grid();
	return ok1 && ok2;
}

/**
 * Tests to make sure the doodlebug moves to the cell it is told to move to.
 * @return true if pass, false if fail
 */
bool Tests2::testDoodlebugMove() {
	std::cout << "Running testDoodlebugMove" << std::endl;
	Cell* cell = new Cell();
	cell->setPosition(3, 2);
	std::cout << "Cell position is (" << cell->getRow() << "," << cell->getCol() << ")" << std::endl;
	std::cout << "Cell's current occupant is " << cell->getOccupant() << " and in this case, 0 is empty, 1 is ant, 2 is doodlebug" << std::endl;
	Doodlebug* bug = new Doodlebug(2,1);
	std::cout << "Doodlebug position is (" << bug->getRow() << "," << bug->getCol() << ")" << std::endl;
	std::cout << "Commencing movement" << std::endl;
	bug->move(cell);
	std::cout << "Movement complete" << std::endl;
	std::cout << "Doodlebug position is (" << bug->getRow() << "," << bug->getCol() << ")" << std::endl;
	std::cout << "Cell's current occupant is " << cell->getOccupant() << " and in this case, 0 is empty, 1 is ant, 2 is doodlebug" << std::endl;
	bool ok1 = bug->getRow() == 3;
	bool ok2 = bug->getCol() == 2;
	bool ok3 = cell->getOccupant() == doodlebug;
	cell->~Cell();
	bug->~Doodlebug();
	return ok1 && ok2 && ok3;
}

/**
 * Tests to make sure the doodlebug can breed and if it can't, won't.
 * @return true if pass, false if fail
 */
bool Tests2::testDoodlebugBreed() {
	std::cout << "Running testDoodlebugBreed" << std::endl;
	Cell* cell = new Cell();
	Cell* breedInto = new Cell();
	cell->setPosition(3, 2);
	breedInto->setPosition(4,2);
	Doodlebug* bug = new Doodlebug(2,1);
	bug->move(cell);
	bug->move(cell);
	bug->move(cell);
	bug->move(cell);
	bool ok1 = !bug->breed(breedInto);
	std::cout << "Doodlebug has moved 4 times. It should not be able to breed. It was " << ok1 << " that it was unable to breed. 0 = false, 1 = true" << std::endl;
	bug->move(cell);
	bug->move(cell);
	bug->move(cell);
	bug->move(cell);
	std::cout << "The breeding cell's current occupant is " << breedInto->getOccupant() << " and in this case, 0 is empty, 1 is ant, 2 is doodlebug" << std::endl;
	bool ok2 = bug->breed(breedInto);
	std::cout << "Doodlebug has moved 8 times. It should be able to breed. It was " << ok2 << " that it was able to breed. 0 = false, 1 = true" << std::endl;
	bool ok3 = breedInto->getOccupant() == doodlebug;
	std::cout << "The breeding cell's current occupant is " << breedInto->getOccupant() << " and in this case, 0 is empty, 1 is ant, 2 is doodlebug" << std::endl;
	bug->move(cell);
	bug->move(cell);
	bug->move(cell);
	Cell* breed2 = new Cell();
	bool ok4 = !bug->breed(breedInto);
	std::cout << "Doodlebug has moved 3 more times. It should not be able to breed. It was " << ok4 << " that it was unable to breed. 0 = false, 1 = true" << std::endl;
	cell->~Cell();
	breedInto->~Cell();
	bug->~Doodlebug();
	breed2->~Cell();
	return ok1 && ok2 && ok3 && ok4;
}

/**
 * Tests to make sure the doodlebug starve function returns the correct boolean.
 * @return true if pass, false if fail
 */
bool Tests2::testDoodlebugStarve() {
	std::cout << "Running testDoodlebugStarve" << std::endl;
	Cell* cell = new Cell();
	cell->setPosition(3, 2);
	Doodlebug* bug = new Doodlebug(2,1);
	bug->move(cell);
	bug->move(cell);
	bool ok1 = !bug->starve();
	std::cout << "Doodlebug has moved 2 times. It should not starve. It was " << ok1 << " that it did not starve. 0 = false, 1 = true" << std::endl;
	bug->move(cell);
	bool ok2 = bug->starve();
	std::cout << "Doodlebug has moved 3 times. It should starve. It was " << ok2 << " that it starved. 0 = false, 1 = true" << std::endl;
	cell->~Cell();
	bug->~Doodlebug();
	return ok1 && ok2;
}

/**
 * Tests whether the ant moves into the cell it was told to move into
 * @return true if pass, false if fail
 */
bool Tests2::testAntMove() {
	std::cout << "Running testAntMove" << std::endl;
	Cell* cell = new Cell();
	cell->setPosition(3, 2);
	std::cout << "Cell position is (" << cell->getRow() << "," << cell->getCol() << ")" << std::endl;
	std::cout << "Cell's current occupant is " << cell->getOccupant() << " and in this case, 0 is empty, 1 is ant, 2 is doodlebug" << std::endl;
	Ant* bug = new Ant(2,1);
	std::cout << "Ant position is (" << bug->getRow() << "," << bug->getCol() << ")" << std::endl;
	std::cout << "Commencing movement" << std::endl;
	bug->move(cell);
	std::cout << "Movement complete" << std::endl;
	std::cout << "Ant position is (" << bug->getRow() << "," << bug->getCol() << ")" << std::endl;
	std::cout << "Cell's current occupant is " << cell->getOccupant() << " and in this case, 0 is empty, 1 is ant, 2 is doodlebug" << std::endl;
	bool ok1 = bug->getRow() == 3;
	bool ok2 = bug->getCol() == 2;
	bool ok3 = cell->getOccupant() == ant;
	cell->~Cell();
	bug->~Ant();
	return ok1 && ok2 && ok3;
}

/**
 * Tests whether the ant breeds correctly or not
 * @return true if pass, false if fail
 */
bool Tests2::testAntBreed() {
	std::cout << "Running testDoodlebugBreed" << std::endl;
	Cell* cell = new Cell();
	Cell* breedInto = new Cell();
	cell->setPosition(3, 2);
	breedInto->setPosition(4,2);
	Ant* bug = new Ant(2,1);
	bug->move(cell);
	bug->move(cell);
	bool ok1 = !bug->breed(breedInto);
	std::cout << "Ant has moved 2 times. It should not be able to breed. It was " << ok1 << " that it was unable to breed. 0 = false, 1 = true" << std::endl;
	bug->move(cell);
	std::cout << "The breeding cell's current occupant is " << breedInto->getOccupant() << " and in this case, 0 is empty, 1 is ant, 2 is doodlebug" << std::endl;
	bool ok2 = bug->breed(breedInto);
	std::cout << "Ant has moved 3 times. It should be able to breed. It was " << ok2 << " that it was able to breed. 0 = false, 1 = true" << std::endl;
	bool ok3 = breedInto->getOccupant() == ant;
	std::cout << "The breeding cell's current occupant is " << breedInto->getOccupant() << " and in this case, 0 is empty, 1 is ant, 2 is doodlebug" << std::endl;
	bug->move(cell);
	bug->move(cell);
	Cell* breed2 = new Cell();
	bool ok4 = !bug->breed(breedInto);
	std::cout << "Ant has moved 2 more times. It should not be able to breed. It was " << ok4 << " that it was unable to breed. 0 = false, 1 = true" << std::endl;
	cell->~Cell();
	breedInto->~Cell();
	bug->~Ant();
	breed2->~Cell();
	return ok1 && ok2 && ok3 && ok4;
}
Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

