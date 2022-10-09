#include "Command.h"
#include "Connection.h"
using namespace std;

int main()
{
    Connection *connection = NULL;
    string input, command;
    connection = new Connection;
    connection->Connect(6379, "127.0.0.1");
    Command<int, int> cmd;
    cmd.FlushDB(connection);
    cmd.FlushAll(connection);
    double keys = cmd.NumofKeysDB(connection);
    std::string reply;
    double all_keys=cmd.NumofAllKeys(connection);
    cmd.SelectDB(connection,63);
    return 0;
}