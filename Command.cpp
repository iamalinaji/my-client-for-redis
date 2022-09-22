#include "Command.hpp"
template <typename K, typename T> Command<K, T>::Command(serverapi *server_)
{
    this->DB_pt = this->Select_DataBase();
    this->server = server_;
}