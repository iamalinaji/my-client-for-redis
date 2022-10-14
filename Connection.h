#ifndef CONNECTION_H
#define CONNECTION_H
#include "Server.h"
#include <string>
class Connection
{
  private:
    ServerApi *server = NULL;

  public:
    std::string SendCommand(std::string redis_valid_command,bool server_reply_to_be_shown=true);
    void Connect(int port, std::string ip);
    void Disconnect();
    ServerApi *get_server()
    {
        return server;
    }
};

#endif