#ifndef CONNECTION_HPP
#define CONNECTION_HPP
#include "redis.hpp"
#include "server.hpp"
#include <string>
class Connection : public Redis
{
  protected:
    serverapi *server=NULL;

  public:
    void Connect(int port, std::string ip);
    serverapi *get_server()
    {
        return server;
    }
};


#endif