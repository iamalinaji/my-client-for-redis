#include "Command.h"
#include "iostream"
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
template <typename K, typename T> double Command<K, T>::num_of_all_keys(Connection *c)
{
    std::string reply = c->send_command_and_show_reply("CONFIG GET databases", false);
    int databases = std::stod(reply);
    double keys = 0;
    int index = this->current_db_index;
    for (int i = 0; i < databases; i++)
    {
        this->select_db(c, i, false);
        keys += (this->num_of_keys_db(c));
    }
    this->select_db(c, index, false);
    return keys;
}
template <typename K, typename T> bool Command<K, T>::select_db(Connection *c, int index, bool check_index)
{
    if (check_index)
    {
        int databases = std::stod(c->send_command_and_show_reply("CONFIG GET databases", false));
        if (index >= databases)
            return false;
    }
    c->send_command_and_show_reply(("Select " + std::to_string(index)));
    this->current_db_index=index;
    return true;
}