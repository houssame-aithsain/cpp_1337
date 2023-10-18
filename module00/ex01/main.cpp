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
        std::cout << std::endl << "=>\t";
        std::cin >> str;
        std::cout << std::endl;
        if (std::cin.eof())
            exit(0);
        if (std::cin.fail()){
            std::cin.ignore();
            std::cin.clear();
        }
    }
}
