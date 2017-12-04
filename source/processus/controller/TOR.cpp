/*
 * TOR.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#include "TOR.h"

TOR::TOR(unsigned ID, string name, Process* server, Process* state, double val_sat, double consigne) :
 Control(ID, name, server, state, val_sat, consigne) {

}

TOR::~TOR() {
	// TODO Auto-generated destructor stub
}

void TOR::update() {
	double etat_curr = state_->etatCurr();
	State* etat = dynamic_cast <State*> ( state_ );
	if(etat_curr <= consigne_) {
		etat->set_valCtrl(val_sat_);
	}
	else {
		etat->set_valCtrl(0);
	}
}

