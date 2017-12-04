/*
 * State.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "State.h"

State::State(unsigned ID, string name, double state_curr, double i_phen, double i_ctrl, double val_phen)
	: State_curr_(state_curr), I_phen_(i_phen), I_ctrl_(i_ctrl), val_phen_(val_phen), val_ctrl_(0.0), Process(ID, name) {

}

State::State(unsigned ID, string name, double i_phen, double i_ctrl)
	: State_curr_(0.0), I_phen_(i_phen), I_ctrl_(i_ctrl), val_phen_(0.0), val_ctrl_(0.0), Process(ID, name) {

}

State::~State() {

}


void State::update() {
	State_curr_ = State_curr_
			+ (val_phen_ - State_curr_) * I_phen_
			+ (val_ctrl_ - State_curr_) * I_ctrl_;
}
