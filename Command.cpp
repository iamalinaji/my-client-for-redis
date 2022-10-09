#include "Command.h"
#include "string"

template <typename K, typename T> void Command<K, T>::flushdb(Connection *c)
{
    c->send_command_and_show_reply("FLUSHDB", false);
}
template <typename K, typename T> void Command<K, T>::flushall(Connection *c)
{
    c->send_command_and_show_reply("FLUSHALL", false);
}
template <typename K, typename T> double Command<K, T>::num_of_keys_db(Connection *c)
{
    std::string reply = c->send_command_and_show_reply("dbsize", false);
    double result = std::stod(reply);
    return result;
}