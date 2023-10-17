#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook Book;
    std::string str;

    book.ContactsEraser();
    Book.Usage();
    while (str.compare("EXIT"))
    {
        if (!str.compare("ADD"))
            Book.AddContact();
        if (!str.compare("SEARCH"))
            Book.SearchForContact();
        str.erase();
        std::cin >> str;
    }
}
