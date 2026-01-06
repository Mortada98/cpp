#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _count(0)
{
}   

static std::string getInput(const std::string &prompt)
{
    std::string input;

    while (input.empty())
    {
        std::cout << CYAN << "  " << prompt << RESET << ": ";
        if (!std::getline(std::cin, input))
            return "";
        if (input.empty())
            std::cout << RED << "  ⚠ Field cannot be empty!\n" << RESET;
    }
    return input;
}

static std::string truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::add()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << BOLD << MAGENTA << "\n➕ Add New Contact\n" << RESET;
    std::cout << CYAN << "─────────────────────\n" << RESET;

    firstName = getInput("First Name");
    if (firstName.empty()) return;
    lastName = getInput("Last Name");
    if (lastName.empty()) return;
    nickname = getInput("Nickname");
    if (nickname.empty()) return;
    phoneNumber = getInput("Phone Number");
    if (phoneNumber.empty()) return;
    darkestSecret = getInput("Darkest Secret");
    if (darkestSecret.empty()) return;

    _contacts[_index].setFirstName(firstName);
    _contacts[_index].setLastName(lastName);
    _contacts[_index].setNickname(nickname);
    _contacts[_index].setPhoneNumber(phoneNumber);
    _contacts[_index].setDarkestSecret(darkestSecret);
    _index = (_index + 1) % 8;
    if (_count < 8)
        _count++;

    std::cout << GREEN << "  ✓ Contact saved successfully!\n\n" << RESET;
}

void PhoneBook::search()
{
    std::string input;
    int index;

    if (_count == 0)
    {
        std::cout << RED << "\n  ⚠ PhoneBook is empty!\n\n" << RESET;
        return;
    }

    std::cout << BOLD << MAGENTA << "\n🔍 Search Contacts\n" << RESET;
    std::cout << CYAN << "─────────────────────────────────────────────\n" << RESET;
    std::cout << CYAN << "|" << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|\n" << RESET;
    std::cout << CYAN << "─────────────────────────────────────────────\n" << RESET;

    for (int i = 0; i < _count; i++)
    {
        std::cout << CYAN << "|" << RESET;
        std::cout << std::setw(10) << i << CYAN << "|" << RESET;
        std::cout << std::setw(10) << truncate(_contacts[i].getFirstName()) << CYAN << "|" << RESET;
        std::cout << std::setw(10) << truncate(_contacts[i].getLastName()) << CYAN << "|" << RESET;
        std::cout << std::setw(10) << truncate(_contacts[i].getNickname()) << CYAN << "|" << RESET << "\n";
    }
    std::cout << CYAN << "─────────────────────────────────────────────\n" << RESET;

    std::cout << YELLOW << "\n  Enter index to view details: " << RESET;
    if (!std::getline(std::cin, input) || input.empty())
        return;

    index = -1;
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
        index = input[0] - '0';

    if (index < 0 || index >= _count)
    {
        std::cout << RED << "  ⚠ Invalid index!\n\n" << RESET;
        return;
    }

    print(index);
}

void PhoneBook::print(int index)
{
    std::cout << BOLD << MAGENTA << "\n📋 Contact Details\n" << RESET;
    std::cout << CYAN << "─────────────────────\n" << RESET;
    std::cout << GREEN << "  First Name     : " << RESET << _contacts[index].getFirstName() << "\n";
    std::cout << GREEN << "  Last Name      : " << RESET << _contacts[index].getLastName() << "\n";
    std::cout << GREEN << "  Nickname       : " << RESET << _contacts[index].getNickname() << "\n";
    std::cout << GREEN << "  Phone Number   : " << RESET << _contacts[index].getPhoneNumber() << "\n";
    std::cout << GREEN << "  Darkest Secret : " << RESET << _contacts[index].getDarkestSecret() << "\n\n";
}
