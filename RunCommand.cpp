#include "RunCommand.h"
void run_db_type_command(Connection *connection, CommandParse type, std::stringstream &ss)
{
    Command<int, int> *commandtype_var;
    commandtype_var = new Command<int, int>(connection->get_server());
    switch (type)
    {
    case CommandParse::select_db:
        if (connection->get_server() != NULL)
        {
            std::string command_to_server;
            int db_index;
            ss >> db_index;
            commandtype_var->Select_DataBase(db_index);
            command_to_server = "Select " + std::to_string(db_index);
            connection->send_command_and_show_reply(command_to_server);
        }
        break;
    case CommandParse::flush_db:
        commandtype_var->flushdb(connection);
        break;
    case CommandParse::flush_all:
        commandtype_var->flush_all(connection);
        break;
    case CommandParse::num_of_keys_db:
        commandtype_var->num_of_keys(connection);
        break;

    case CommandParse::num_of_all_keys:
        commandtype_var->num_of_all_keys(connection);
        break;
    }
}