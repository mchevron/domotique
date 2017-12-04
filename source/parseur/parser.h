/*
 * xml_extract.h
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#ifndef SOURCE_PARSER_H_
#define SOURCE_PARSER_H_

#include "../../TinyXML/tinyxml.h"
#include "../processus/Phenomenon.h"
#include "../processus/State.h"
#include "../processus/Control.h"
#include "../processus/Server.h"
#include "../processus/Process.h"
#include "../Simulator.h"
#include <vector>
#include <string>

using namespace std;

Simulator* parser();

#endif /* SOURCE_PARSER_H_ */
