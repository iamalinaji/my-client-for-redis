#ifndef PARSE_HPP
#define PARSE_HPP
#include <string>
enum class CommandParse
{
    connect,
    select_db,
    flush_db,
    flush_all,
    num_of_keys_db,
    num_of_all_keys
};
CommandParse parse_command(std::string input)
{
    if (input == "select")
        return CommandParse::select_db;
    else if (input == "connect")
        return CommandParse::connect;
    else if (input == "flushdb")
        return CommandParse::flush_db;
    else if (input == "flushall")
        return CommandParse::flush_all;
    else if (input == "num_of_keys_in_db")
        return CommandParse::num_of_keys_db;
}

#endif