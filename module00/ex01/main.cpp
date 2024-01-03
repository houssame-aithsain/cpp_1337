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
        std::cout << std::endl << "HOME$>\t";
        std::cin >> std::ws >> str;
        std::cout << std::endl;
        if (std::cin.eof())
            std::exit(0);
    }
}
