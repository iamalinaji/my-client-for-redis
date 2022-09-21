#ifndef DATABASE_HPP
#define DATABASE_HPP


class DataBase
{
  private:
    int num_of_keys = 0;

  public:
    void flush_db();
    void decrease_keys_num();
    void increase_keys_num();
};

#endif
