#ifndef RUNCOMMAND_HPP
#define RUNCOMMAND_HPP
#include "Command.hpp"
#include "Connection.hpp"
#include "parse.hpp"
#include <iostream>
#include <sstream>

void run_db_type_command(Connection *connection, CommandParse type, std::stringstream &ss);



#endif