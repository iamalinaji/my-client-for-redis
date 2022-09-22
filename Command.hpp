#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "Connection.hpp"
#include "DataBase.hpp"
template <typename K, typename T> class Command : public Connection
{
  private:
    DataBase *DB_pt;
    serverapi *server;

  public:
    Command(serverapi* server_);
    bool exists(K);
    void del_key(K);
    T insert(K, T);
    T get_key(K);
};
#endif