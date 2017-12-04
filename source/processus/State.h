/*
 * State.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_State_H_
#define SOURCES_PROCESSUS_State_H_

#include "Process.h"

class State: public Process {
public:
	State(unsigned ID, string name, double state_curr, double i_phen, double i_ctrl, double val_phen);
	State(unsigned ID, string name, double i_phen, double i_ctrl);
	virtual ~State();

	//setters
	void set_valCtrl(double val) { val_ctrl_ = val; }

	//autres
	void calcul(double val_ctrl);
	virtual void update();
	virtual double workValphen(double val = 0, bool set = false) { if(set){val_phen_ = val;} return val_phen_; }
	virtual double etatCurr(double val = 0, bool set = false) { if(set){State_curr_ = val;} return State_curr_; }
private:
	double State_curr_;
	double I_phen_;
	double I_ctrl_;
	double val_phen_;
	double val_ctrl_;
};

#endif /* SOURCES_PROCESSUS_State_H_ */
