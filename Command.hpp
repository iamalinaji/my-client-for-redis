#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "Connection.hpp"
template <typename K, typename T> class Command : public Connection
{
  private:
    DataBase *DB_pt;

  public:
    Command(int port,std::string ip);
    bool exists(K);
    void del_key(K);
    T insert(K,T);
    T get_key(K);
};
#endif