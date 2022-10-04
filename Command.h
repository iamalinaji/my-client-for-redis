#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "DataBase.h"
#include "Redis.h"
#include "Server.h"
template <typename K, typename T> class Command : public Redis
{
  private:
    DataBase *DB_pt;
    ServerApi *server;

  public:
    Command(ServerApi *server_)
    {
        this->DB_pt = this->Select_DataBase();
        this->server = server_;
    }
    void flushdb(Connection* c){DB_pt->flush_db(c);}
    void num_of_keys(Connection *c){DB_pt->show_num_of_keys_in_db(c);}
    bool exists(K);
    void del_key(K);
    T insert(K, T);
    T get_key(K);
};
#endif