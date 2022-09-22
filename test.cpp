#include "Connection.hpp"
#include <hiredis/hiredis.h>
using namespace std;

int main()
{
    Connection C(6379,"127.0.0.1");
    redisContext* myContext;
    myContext=redisConnect("127.0.0.1",6379);
    return 0;
}