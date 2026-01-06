#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   book;
    std::string input;
    

    std::cout << BOLD << MAGENTA << "\n📞 Welcome to PhoneBook \n" << RESET;
    std::cout << CYAN << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << RESET;
    while (1)
    {
        std::cout << BOLD << GREEN << "📖 PhoneBook" << RESET << " > ";
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            break;
        }
        if (input == "EXIT")
        {
            std::cout << YELLOW << "👋 Goodbye!\n" << RESET;
            break;
        }
        else if (input == "ADD")
            book.add();
        else if (input == "SEARCH")
            book.search();
        else
            std::cout << YELLOW << "⚡ Commands: " << BOLD << "ADD" << RESET
                      << YELLOW << ", " << BOLD << "SEARCH" << RESET
                      << YELLOW << ", " << BOLD << "EXIT" << RESET << std::endl;
    }
    return (0);
}