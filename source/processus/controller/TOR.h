/*
 * TOR.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_CONTROLLER_TOR_H_
#define SOURCES_PROCESSUS_CONTROLLER_TOR_H_

#include "../Control.h"

class TOR : public Control {
public:
	TOR(unsigned ID, string name, Process* server, Process* state, double val_sat, double consigne);
	virtual ~TOR();
	void update();
	virtual double workValphen(double val = 0, bool set = false) { return NULL; }
	virtual double etatCurr(double val = 0, bool set = false) { return NULL; }
};

#endif /* SOURCES_PROCESSUS_CONTROLLER_TOR_H_ */
