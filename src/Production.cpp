/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Production.h"

Production::Production(int argc, char* argv[]) {
	// TODO Auto-generated constructor stub
	timestepsLeft = 100; //initialize available timesteps
}

bool Production::runProduction()
{
	bool result = true;
	while(timestepsLeft-- > 0)
	{
		//dbs.step;
		//ants.step;
	}
	return result;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

