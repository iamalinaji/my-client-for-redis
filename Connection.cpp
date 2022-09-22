#include "Connection.hpp"
#include <hiredis/hiredis.h>
#include <cstring>
using namespace std;
void Connection::Connect(int port, string ip)
{
    char ip_arr[ip.length()+1];
    strcpy(ip_arr,ip.c_str());
    this->server=(redisContext*)redisConnect(ip_arr,port);
}
