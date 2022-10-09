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
    reply=connection->send_command_and_show_reply("CONFIG GET SERVER");
    return 0;
}