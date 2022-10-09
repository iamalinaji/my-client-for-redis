#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "Server.h"
#include "Connection.h"
template <typename K, typename T> class Command
{
  private:
    int current_db_index = 0;

  public:
    void flushdb(Connection *c);
    void flushall(Connection *c);
    double num_of_keys_db(Connection *c);
    double num_of_all_keys(Connection *c);
    bool select_db(Connection *c, int index, bool check_index = true);
    bool exists(K);
    void del_key(K);
    T insert(K, T);
    T get_key(K);
};
#include "Command.cpp"
#endif