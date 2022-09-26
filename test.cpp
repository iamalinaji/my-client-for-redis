#include "runcommand.hpp"
using namespace std;

int main()
{
    Connection *connection = NULL;
    string input,command;
    CommandParse CommandType;
    int condition;
    while (getline(cin, input))
    {
        stringstream ss(input);
        ss >> command;
        CommandType = parse_command(command);
        condition=CommandType;
        if(condition<5)
            run_db_type_command(connection,CommandType,ss);
    }
    return 0;
}