#include "Command.h"
#include "Connection.h"
#include <include/gtest/gtest.h>
#include <string>
using namespace std;

TEST(myclienttest, connection)
{
    Connection *connection = NULL;
    string input, command;
    connection = new Connection;
    connection->Connect(6379, "127.0.0.1");
    std::string reply = connection->SendCommand("PING", false);
    ASSERT_EQ("PONG", reply);
}

class MyConnection : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        c = new Connection;
        c->Connect(6379, "127.0.0.1");
        std::string reply = c->SendCommand("CONFIG GET databases", false);
        databases = std::stod(reply);
    }
    void TearDown() override
    {
        c->Disconnect();
        delete (c);
    }
    double databases;
    Connection *c;
};

TEST_F(MyConnection, dbtest)
{
    Command<int, int> cmd;
    cmd.FlushDB(c);
    cmd.FlushAll(c);
    double keys = cmd.NumofKeysDB(c);
    EXPECT_EQ(0, keys);
    double all_keys = cmd.NumofAllKeys(c);
    EXPECT_EQ(0, all_keys);
    for (int i = 0; i < databases; i++)
    {
        EXPECT_EQ(true, cmd.SelectDB(c, i));
    }
    EXPECT_EQ(false, cmd.SelectDB(c, 630));
}

TEST_F(MyConnection, insertiontest)
{
    Command<string, string> cmd;
    cmd.Insert(c,"Ali","Khafan");
    EXPECT_EQ(cmd.NumofKeysDB(c),1);
    EXPECT_EQ(cmd.NumofAllKeys(c),1);
    EXPECT_EQ(cmd.GetKey(c,"Ali"),"Khafan");
}

/*int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/