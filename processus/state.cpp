/*
 * state.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "state.h"

state::state() {

}

state::~state() {
	// TODO Auto-generated destructor stub
}


void state::calcul(double val_ctrl) {
	state_eff_ = state_curr_
			+ (val_phen_ - state_curr_) * I_phen_
			+ (val_ctrl - state_curr_) * I_ctrl_;
	state_curr_ = state_eff_;
}


void state::set_val_phen(double val_phen) { val_phen_ = val_phen; }
