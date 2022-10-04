#ifndef CONNECTION_H
#define CONNECTION_H
#include "Server.h"
#include <string>
class Connection
{
  private:
    ServerApi *server = NULL;

  public:
    std::string send_command_and_show_reply(std::string redis_valid_command,bool server_reply_to_be_shown=true);
    void Connect(int port, std::string ip);
    ServerApi *get_server()
    {
        return server;
    }
};

#endif