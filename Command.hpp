#ifndef COMMAND_HPP
#define COMMAND_HPP
#include "DataBase.hpp"
template <typename K, typename T> class Command 
{
  private:
    DataBase *DB_pt;

  public:
    Command();
    bool exists(K);
    void del_key(K);
    T insert(K,T);
    T get_key(K);
};
#endif