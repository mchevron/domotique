/*
 * processus.h
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */

#ifndef SOURCES_PROCESSUS_PROCESS_H_
#define SOURCES_PROCESSUS_PROCESS_H_

#include <vector>
enum ProcessTyp { STATE, CONTROL, PHENOMEN};
const unsigned NTRIPLET = 3;

using namespace std;

class process {
public:
	process();
	virtual ~process();
	// getters
	process* get_state() const { return triplet_[STATE];}
	process* get_control() const { return triplet_[CONTROL];}
	process* get_phenomen() const { return triplet_[PHENOMEN];}

	// setters
	void set_state(process* state);
	void set_control(process* control);
	void set_phenomen(process* phenomen);

	// autres
	virtual void set_val_phen(double val_phen) const = 0;

protected:
	vector<process*> triplet_;
};

#endif /* SOURCES_PROCESSUS_PROCESS_H_ */
