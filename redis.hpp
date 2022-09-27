#ifndef REDIS_HPP
#define REDIS_HPP
#include "Connection.hpp"
#include "DataBase.hpp"
#include <vector>
class Redis
{
  private:
    std::vector<DataBase> databases = std::vector<DataBase>(64);

  public:
    DataBase *Select_DataBase(int db_index = 0);
    double num_of_all_keys(Connection *c);
    void flush_all(Connection *c);
};

#endif