#include "Command.hpp"
#include <hiredis/hiredis.h>
using namespace std;

int main()
{
    redisContext* myContext;
    myContext=redisConnect("127.0.0.1",6379);
    return 0;
}