#include "Command.h"
#include "iostream"
#include "string"
#include <sstream>

template <typename K, typename T> void Command<K, T>::FlushDB(Connection *c)
{
    c->SendCommand("FLUSHDB", false);
}
template <typename K, typename T> void Command<K, T>::FlushAll(Connection *c)
{
    c->SendCommand("FLUSHALL", false);
}
template <typename K, typename T> double Command<K, T>::NumofKeysDB(Connection *c)
{
    std::string reply = c->SendCommand("dbsize", false);
    double result = std::stod(reply);
    return result;
}
template <typename K, typename T> double Command<K, T>::NumofAllKeys(Connection *c)
{
    std::string reply = c->SendCommand("CONFIG GET databases", false);
    int databases = std::stod(reply);
    double keys = 0;
    int index = this->current_db_index;
    for (int i = 0; i < databases; i++)
    {
        this->SelectDB(c, i, false);
        keys += (this->NumofKeysDB(c));
    }
    this->SelectDB(c, index, false);
    return keys;
}
template <typename K, typename T> bool Command<K, T>::SelectDB(Connection *c, int index, bool check_index)
{
    if (check_index)
    {
        int databases = std::stod(c->SendCommand("CONFIG GET databases", false));
        if (index >= databases)
            return false;
    }
    c->SendCommand(("Select " + std::to_string(index)), false);
    this->current_db_index = index;
    return true;
}

template <typename K, typename T> bool Command<K, T>::Insert(Connection *c, K mykey, T myval)
{
    if (c == NULL)
        return false;
    std::string key = std::to_string(mykey);
    std::string val = std::to_string(myval);
    std::string set = "SET";
    c->SendCommand(set + key + val, false);
    return true;
}

template <typename K, typename T> T Command<K, T>::GetKey(Connection *c, K mykey)
{
    std::string get = "GET";
    std::string reply = c->SendCommand(get + std::to_string(mykey), false);
    return reply;
}
template <typename T> void MyFunc(T val)
{
    std::stringstream ss;
    ss >> val;
}