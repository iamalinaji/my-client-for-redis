#include "Command.hpp"

template <typename K, typename T> Command<K, T>::Command(int port, std::string ip)
    : Connection(port, ip)
{
    this->DB_pt = this->Select_DataBase();
}