#ifndef DATABASE_HPP
#define DATABASE_HPP
#include "Connection.hpp"
#include <string>
class DataBase
{
  private:
    double num_of_keys = 0;

  public:
    void flush_db(Connection *c);
    void show_num_of_keys_in_db(Connection *c);
};

#endif
