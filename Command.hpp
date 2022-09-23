#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "redis.hpp"
#include "server.hpp"
#include "DataBase.hpp"
template <typename K, typename T> class Command : public Redis
{
  private:
    DataBase *DB_pt;
    serverapi *server;

  public:
    Command(serverapi *server_)
    {
        this->DB_pt = this->Select_DataBase();
        this->server = server_;
    }
    bool exists(K);
    void del_key(K);
    T insert(K, T);
    T get_key(K);
};
#endif