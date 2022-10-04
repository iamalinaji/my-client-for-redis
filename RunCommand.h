#ifndef RUNCOMMAND_H
#define RUNCOMMAND_H
#include "Command.h"
#include "Connection.h"
#include "Parse.h"
#include <iostream>
#include <sstream>

void run_db_type_command(Connection *connection, CommandParse type, std::stringstream &ss);



#endif