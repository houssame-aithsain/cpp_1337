#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook Book;
    std::string str;

    Book.init();
    Book.Usage();
    while (str.compare("EXIT"))
    {
        if (!str.compare("ADD"))
            Book.AddContact();
        if (!str.compare("SEARCH"))
            Book.SearchForContact();     
        std::cin >> str;
        if (std::cin.eof())
            exit(0);
        if (std::cin.fail()){
            std::cin.ignore();
            std::cin.clear();
        }
    }
}
