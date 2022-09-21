#ifndef CONNECTION_HPP
#define CONNECTION_HPP
#include "redis.hpp"
#include "server.hpp"
#include <string>
class Connection : public Redis
{
  private:
    serverapi *server;

  public:
    Connection(int port, std::string ip);
};

#endif