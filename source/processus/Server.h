/*
 * server.h
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

#ifndef SOURCE_SERVER_H_
#define SOURCE_SERVER_H_
#include "Process.h"
#include "..\Simulator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Server : public Process {
public:
	Server(string tick_unit);
	virtual ~Server();

	virtual void update();
	virtual double workValphen(double val = 0, bool set = false) { return NULL; }
	virtual double etatCurr(double val = 0, bool set = false) { return NULL; }

	//Journal
	void create_file();
	void log_file(string text);
	void set_filename() {
		filename_.push_back("journal");
	}

	//GNU
	void create_file(int zone_ID);
	void log_file(double value, bool end_line, int zone_ID);
	void set_filename(int zone_ID) {
		std::string ID = std::to_string(zone_ID);
		filename_.push_back("gnu_zone_"+ID);
	};
	string get_filename(int zone_ID) {
		return filename_[zone_ID - 1];
	};

	//close all files
	void close_files();

private:
	vector<ofstream*> file_;
	vector<string> filename_;
	string tick_unit_;
};



#endif /* SOURCE_SERVER_H_ */
