#include "Command.hpp"

template <typename K, typename T> Command<K, T>::Command()
{
    this->DB_pt = this->Select_DataBase();
}