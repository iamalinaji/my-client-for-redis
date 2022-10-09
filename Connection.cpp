#include "Connection.h"
#include <cstring>
#include <hiredis/hiredis.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void ShowStateofConnection(ServerApi *server)
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
    ShowStateofConnection(this->server);
}
string Connection::SendCommand(string redis_valid_command, bool server_reply_to_be_shown)
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
        if (server_reply_to_be_shown)
            std::cout << reply->integer << std::endl;
    }
    else if(reply->type == REDIS_REPLY_ARRAY)
    {
        ss<<reply->element[1]->str;
        if (server_reply_to_be_shown)
            std::cout << reply->element[1]->str << std::endl;
    }
    else
    {
        ss << reply->str;
        if (server_reply_to_be_shown)
            std::cout << reply->str << std::endl;
    }
    ss >> replysentence;
    return replysentence;
}
