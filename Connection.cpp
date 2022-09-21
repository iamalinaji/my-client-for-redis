#include "Connection.hpp"
#include <cstring>
using namespace std;
Connection::Connection(int port, string ip)
{
    char ip_arr[ip.length()+1];
    strcpy(ip_arr,ip.c_str());
    server=(redisContext*)redisConnect(ip_arr,port);
}
