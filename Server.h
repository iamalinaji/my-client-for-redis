#ifndef SERVER_H
#define SERVER_H
#include <hiredis/hiredis.h>
typedef redisContext ServerApi;
typedef redisReply ServerReply;
#endif