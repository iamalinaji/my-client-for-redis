#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "DataBase.h"
#include "Redis.h"
#include "Server.h"
template <typename K, typename T> class Command
{
  private:
  public:
    void flushdb(Connection *c);
    void flushall(Connection *c);
    double num_of_keys_db(Connection *c);
    double num_of_all_keys(Connection *c);
    bool select_db(Connection *c);
    bool exists(K);
    void del_key(K);
    T insert(K, T);
    T get_key(K);
};
#include "Command.cpp"
#endif