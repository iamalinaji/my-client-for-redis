#ifndef PARSE_H
#define PARSE_H
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
CommandParse parse_command(std::string input);
#endif