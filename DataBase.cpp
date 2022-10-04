#include <iostream>
#include "DataBase.h"
#include "hiredis/hiredis.h"
void DataBase::flush_db(Connection *c,int send_command_to_db)
{
    if(send_command_to_db)c->send_command_and_show_reply("flushdb");
    num_of_keys = 0;
}
void DataBase::show_num_of_keys_in_db(Connection *c,bool server_reply_to_be_shown)
{
    std::string reply;
    reply = c->send_command_and_show_reply("dbsize",server_reply_to_be_shown);
    num_of_keys = std::stod(reply);
}