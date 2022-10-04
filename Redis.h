#ifndef REDIS_H
#define REDIS_H
#include "Connection.h"
#include "DataBase.h"
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