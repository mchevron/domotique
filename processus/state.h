/*
 * state.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_STATE_H_
#define SOURCES_PROCESSUS_STATE_H_

#include "process.h"

class state: public process {
public:
	state();
	virtual ~state();
	//getters

	//setters
	virtual void set_val_phen(double val_phen);

	//autres
	void calcul(double val_ctrl);
private:
	double state_eff_;
	double state_curr_;
	double I_phen_;
	double I_ctrl_;
	double val_phen_;
};

#endif /* SOURCES_PROCESSUS_STATE_H_ */
