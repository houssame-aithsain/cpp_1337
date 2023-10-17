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
    }
}
