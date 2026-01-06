#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"

class PhoneBook
{
private:
    Contact _contacts[8];
    int _index;
    int _count;

public:
    PhoneBook();
    void add();
    void search();
    void print(int index);
};

#endif