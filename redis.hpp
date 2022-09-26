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
    DataBase *Select_DataBase(int db_index = 0)
    {
        return &databases[db_index - 1];
    }
    double num_of_all_keys();
    void flush_all(Connection *c)
    {
      for (int i=0;i<databases.size();i++){
        databases[i].flush_db(c);
      }
    }
};

#endif