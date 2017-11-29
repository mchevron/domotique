/*
 * simulator.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: pcoo_local
 */


#include "Simulator.h"

Simulator::Simulator(vector<Process*> Process_list, int nTicks) : Process_list_(Process_list), nTicks_(nTicks) {

}

Simulator::~Simulator() {}


void Simulator::run() {

	int i = 0;
	int zone_count = 0;

	//creation des fichiers GNU
	while(Process_list_[i]!=0) {
		zone_count += 1;
		Process_list_.end()->create_file(zone_count); //creates and open a file for every zone
		i+=3;
	}

	//mise à jour et log des valeurs à chaque step:
	for(int iTick = 0; iTick < nTicks_; iTick++) {
		i = 0;
		for(i = 0; i < Process_list_.size(); i ++) {
			Process_list_[i]->udpate();
		}
	}

	//Fermeture des fichiers:
	Process_list_.end()->close_files();

}
