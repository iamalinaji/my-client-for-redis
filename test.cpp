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
    cmd.flushdb(connection);
    cmd.flushall(connection);
    double keys = cmd.num_of_keys_db(connection);
    std::string reply;
    double all_keys=cmd.num_of_all_keys(connection);
    cmd.select_db(connection,63);
    return 0;
}