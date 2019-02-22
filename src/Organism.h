/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism {
public:
	Organism();
	Organism(bool b);
	bool isPrey();
	virtual bool move();
	virtual bool breed();
	virtual bool starve();
	void setAmAnt(bool b);
	virtual ~Organism();
private:
	bool amAnt;
protected:
	int timeStepsSurvived;
};

#endif /* ORGANISM_H_ */
