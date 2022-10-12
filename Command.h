#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "Connection.h"
#include "Server.h"
template <typename K, typename T> class Command
{
  private:
    int current_db_index = 0;

  public:
    void FlushDB(Connection *c);
    void FlushAll(Connection *c);
    double NumofKeysDB(Connection *c);
    double NumofAllKeys(Connection *c);
    bool SelectDB(Connection *c, int index, bool check_index = true);
    bool Exists(K);
    void DelKey(K);
    bool Insert(Connection *c, K, T);
    T GetKey(Connection *c, K);
};
#include "Command.cpp"
#endif