#include "Command.h"
#include "Connection.h"
#include <gtest/gtest.h>
using namespace std;

TEST(myclienttest,connection)
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
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}