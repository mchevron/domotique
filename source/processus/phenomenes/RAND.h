/*
 * Random.h
 *
 *  Created on: Nov 27, 2017
 *      Author: pcoo13
 */

#ifndef SOURCES_PHENOMENES_RANDOM_H_
#define SOURCES_PHENOMENES_RANDOM_H_

#include "../Phenomenon.h"

class RAND : public Phenomenon {
public:
	RAND(unsigned ID, string name, Process* state, double val_min, double val_max);
	virtual ~RAND();
	void update();
private:
	double val_min_;
	double val_max_;
};

#endif /* SOURCES_PHENOMENES_RANDOM_H_ */
