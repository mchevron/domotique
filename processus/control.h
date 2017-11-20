/*
 * control.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_CONTROL_H_
#define SOURCES_PROCESSUS_CONTROL_H_

#include "process.h"

class control: public process {
public:
	control();
	virtual ~control();
	void set_val_phen(double val_phen);
private:
	double val_sat_;
};

#endif /* SOURCES_PROCESSUS_CONTROL_H_ */
