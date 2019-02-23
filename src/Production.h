/*
 * Production.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

/**
 * The production class runs the program as specified by the command line inputs
 */
class Production {
public:
	Production(int argc, char* argv[]);
	bool runProduction(int argc, char* argv[]);
	virtual ~Production();
private:
	int gridSize = 20;
	int doodle = 5;
	int ant = 100;
	int time_steps = 1000;
	int seed = 1;
	int pause = 0;
};

#endif /* PRODUCTION_H_ */
