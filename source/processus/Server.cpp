/*
 * server.cpp
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

#include "Server.h"

Server::Server(string tick_unit): tick_unit_(tick_unit) {}

Server::~Server() {}

//JOURNAL
void Server::create_file() {
	ofstream myfile;
	myfile.open("journal.txt");
	file_.emplace_back(myfile);
}

void Server::log_file(string text) {
	file_[0] << text << endl;
}


//GNU
void Server::create_file(int zone_ID) {
	int filename;
	Server::set_filename(zone_ID);
	ofstream myfile;
	myfile.open(get_filename(zone_ID) + ".txt");
	file_.emplace_back(myfile);
	file_.end() << "# time[" << tick_unit_ << "]   val_phen   state_curr    val_control" << endl;
}

void Server::log_file(double value, bool end_line, int zone_ID) {
	ofstream myfile(Server::get_filename(zone_ID));
	if(end_line) file_[zone_ID] << value << endl;
	else file_[zone_ID] << value << " ";
}

//Close all files
void Server::close_files() {
	int i;
	for(i = 0; i < filename_.size; i++) {
		file_[i].close();
	}
}
