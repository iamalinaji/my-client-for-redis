#ifndef CONNECTION_HPP
#define CONNECTION_HPP
#include "server.hpp"
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