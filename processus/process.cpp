/*
 * processus.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "process.h"

process::process() {
	for( int i = 0, c = NTRIPLET; i < c; i++) {
		triplet_[i] = NULL;
	}
}

process::~process() {
	// TODO Auto-generated destructor stub
}

// setters
void process::set_state(process* state) {
	for(int i = 0, c = NTRIPLET; i < c; i++) {
		if(triplet_[i]) {
			triplet_[i]->triplet_[STATE] = state;
		}
	}
}
void process::set_control(process* control) {
	for(int i = 0, c = NTRIPLET; i < c; i++) {
		if(triplet_[i]) {
			triplet_[i]->triplet_[CONTROL] = control;
		}
	}
}
void process::set_phenomen(process* phenomen) {
	for(int i = 0, c = NTRIPLET; i < c; i++) {
		if(triplet_[i]) {
			triplet_[i]->triplet_[PHENOMEN] = phenomen;
		}
	}
}

