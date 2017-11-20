/*
 * phenomenon.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_PHENOMENON_H_
#define SOURCES_PROCESSUS_PHENOMENON_H_

#include <cstdlib>
#include "process.h"

class phenomenon: public process {
public:
	phenomenon();
	virtual ~phenomenon();

	// setters
	virtual void set_val_phen(double val_phen);
private:
	double val_min_;
	double val_max_;
};

#endif /* SOURCES_PROCESSUS_PHENOMENON_H_ */
