#ifndef SERVER_HPP
#define SERVER_HPP
#include <hiredis/hiredis.h>
typedef redisContext ServerApi;
typedef redisReply ServerReply;
#endif