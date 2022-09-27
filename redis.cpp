#include "redis.hpp"
DataBase* Redis::Select_DataBase(int db_index = 0)
{
    return &databases[db_index - 1];
}
double Redis::num_of_all_keys(Connection *c)
{
    double num_of_all_keys = 0;
    for (int i = 0; i < databases.size(); i++)
    {
        databases[i].show_num_of_keys_in_db(c, false);
    }
    for (int i = 0; i < databases.size(); i++)
    {
        num_of_all_keys += databases[i].num_of_keys;
    }
}
void Redis::flush_all(Connection *c)
{
    for (int i = 0; i < databases.size(); i++)
    {
        databases[i].flush_db(c, 0);
    }
    c->send_command_and_show_reply("flushall");
}