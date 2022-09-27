#include "Connection.hpp"
#include <cstring>
#include <hiredis/hiredis.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void show_state_of_connection(ServerApi *server)
{
    if (server == NULL || server->err)
    {
        if (server)
        {
            printf("Connection error: %s\n", server->errstr);
            redisFree(server);
        }
        else
        {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }
    else
        printf("Connection Successful.\n");
}
void Connection::Connect(int port, string ip)
{
    char ip_arr[ip.length() + 1];
    strcpy(ip_arr, ip.c_str());
    this->server = (ServerApi *)redisConnect(ip_arr, port);
    show_state_of_connection(this->server);
}
string Connection::send_command_and_show_reply(string redis_valid_command)
{
    char format[redis_valid_command.length() + 1];
    strcpy(format, redis_valid_command.c_str());
    ServerReply *reply;
    stringstream ss;
    string replysentence;
    reply = (ServerReply *)redisCommand(this->server, format);
    if (reply->type == REDIS_REPLY_INTEGER)
    {
        ss << reply->integer;
        std::cout << reply->integer << std::endl;
    }
    else
    {
        ss << reply->str;
        std::cout << reply->str << std::endl;
    }
    ss >> replysentence;
    return replysentence;
}
