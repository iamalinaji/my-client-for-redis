#include "Command.h"
#include "Connection.h"
using namespace std;

int main()
{
    Connection *connection = NULL;
    string input, command;
    connection = new Connection;
    connection->Connect(6379,"127.0.0.1");
}