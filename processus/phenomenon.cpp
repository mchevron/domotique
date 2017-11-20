/*
 * phenomenon.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "phenomenon.h"

phenomenon::phenomenon() {
	// TODO Auto-generated constructor stub

}

phenomenon::~phenomenon() {
	// TODO Auto-generated destructor stub
}

void phenomenon::set_val_phen(double val_phen) {
	triplet_[STATE]->set_val_phen(rand() * (val_max_ - val_min_) / RAND_MAX);
}

