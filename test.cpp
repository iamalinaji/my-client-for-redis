#include "Command.hpp"
#include <hiredis/hiredis.h>
using namespace std;

int main()
{
    Connection *c = NULL;
    c = new Connection;
    c->Connect(6379, "127.0.0.1");
    Command<string, string> mycommand(c->get_server());
    return 0;
}