#include <iostream>
#include "DataBase.hpp"
#include "hiredis/hiredis.h"
void DataBase::flush_db(Connection *c)
{
    c->send_command_and_show_reply("flushdb");
    num_of_keys = 0;
}
void DataBase::show_num_of_keys_in_db(Connection *c)
{
    std::string reply;
    reply = c->send_command_and_show_reply("dbsize");
    num_of_keys = std::stod(reply);
    std::cout << num_of_keys << std::endl;
}