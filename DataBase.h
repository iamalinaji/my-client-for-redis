#ifndef DATABASE_H
#define DATABASE_H
#include "Connection.h"
#include <string>
class DataBase
{

  private:
    double num_of_keys = 0;

  public:
    friend class Redis;
    void flush_db(Connection *c,int send_command_to_db=1);
    void show_num_of_keys_in_db(Connection *c,bool server_reply_to_be_shown=true);
};

#endif
